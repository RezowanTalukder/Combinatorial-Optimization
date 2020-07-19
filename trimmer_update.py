import os
import glob
import sys
import soundfile as sf

import mysql
from datetime import datetime, timedelta

# credit: https://stackoverflow.com/a/36461422
from pydub import AudioSegment
from pydub.silence import split_on_silence

copy_data_dir = '/home/audio_trimmer'
brand_list = ['AA','AB']
party_list = ['A','B']
extension_list = ['ulaw','alaw', 'wav']
search_extension_list = ['*.ulaw','*.alaw', '*.wav']
remove_file_sec = 2

data_dir = sys.argv[1]
all_paths = []
c_time = datetime.strftime(datetime.now() - timedelta(1), '%Y_%m_%d')
for ext in search_extension_list:
	paths = glob.glob(os.path.join(data_dir+c_time+'/', ext))
	all_paths = all_paths+paths
	# print(all_paths)
# print(c_time)
# print(data_dir)
# print(data_dir+c_time+'/')
# print(all_paths)
# exit()

totalFile = 0
removeCount = 0

def log_file(string):
	file = open('log_file.txt','a')
	file.write(string+'\n')
	file.close()

for path in all_paths:
	# import pdb
	# pdb.set_trace()
	path_parts = path.split("/")
	filename = path_parts[-1]
	filename_p = filename.split(".")
	filename_name = filename_p[0]
	extension = filename_p[-1]
	opt = ''
	try:
		# check valid file
		full_name_length = len(filename_name)
		brand_name = filename_name[0:2]
		party = filename_name[21:22]
		timestamp = int(filename_name[2:12])
		timestamp_date = datetime.fromtimestamp(timestamp).strftime('%Y-%m-%d')
		if extension == 'ulaw':
			opt = 'u-law'
		elif extension == 'alaw':
			opt = 'a-law'

		# print(full_name_length)
		# print(brand_name)
		# print(party)
		# print(timestamp)
		# print(timestamp_date)
		# print(extension)
		# print(opt)

		if full_name_length == 22 and brand_name in brand_list and party in party_list and extension in extension_list:
			new_file_name = filename_name[2:21]
			new_path = timestamp_date + '/' + new_file_name
			final_data_dir = os.path.join(copy_data_dir, '%s' % new_path)
			# print(final_data_dir)
			# import pdb
			# pdb.set_trace()

			if not os.path.exists(final_data_dir):
				os.makedirs(final_data_dir)
			os.rename(path, final_data_dir + '/' + brand_name + new_file_name + party +'.'+extension)
			main_wav_file_path = final_data_dir + '/' + brand_name + new_file_name + party +'.'+extension
			if extension in ['alaw', 'ulaw']:
				main_ulaw_file_path = final_data_dir + '/' + brand_name + new_file_name + party +'.'+extension
				main_wav_file_path = final_data_dir + '/' + brand_name + new_file_name + party +'.wav'
				print("/usr/bin/sox -t u1 -r 8k -b 8 -c 1 -e "+opt+" "+main_ulaw_file_path+" -r 8000 -b 16 -c 1 -e signed-integer "+main_wav_file_path)
				os.system("/usr/bin/sox -t u1 -r 8k -b 8 -c 1 -e "+opt+" "+main_ulaw_file_path+" -r 8000 -b 16 -c 1 -e signed-integer "+main_wav_file_path)

			# start audio file extract
			sound_file = AudioSegment.from_wav(main_wav_file_path)
			audio_chunks = split_on_silence(sound_file,
				# must be silent for at least half a second
				min_silence_len=2000,
				# consider it silent if quieter than -16 dBFS
				silence_thresh=-32,
				keep_silence=1000
			)

			# update/insert main file information
			db_manager = mysql.DBManager()
			exist_data = db_manager.read_audio_data_by_callid(new_file_name)
			if exist_data:
				audio_data = {
					'callid': new_file_name
				}
				if party == 'A':
					audio_data['a_party'] = 'Y'
				elif party == 'B':
					audio_data['b_party'] = 'Y'
				audio_id = db_manager.update_audio_data(audio_data)
			else:
				audio_data = {
					'callid': new_file_name,
					'user_id': '',
					'status': 'N',
					'brand_name': brand_name,
					'a_party': ('Y' if party == 'A' else 'N'),
					'b_party': ('Y' if party == 'B' else 'N')
				}
				audio_id =  db_manager.insert_audio_data(audio_data)

			file_index = 0
			# import pdb
			# pdb.set_trace()

			# make audio segment
			for ii, chunk in enumerate(audio_chunks):
				chunk_file = new_file_name + '_' + str(file_index) + '.wav'
				if not os.path.exists(final_data_dir + '/' + party):
					os.makedirs(final_data_dir + '/' + party)
				out_file = os.path.join(final_data_dir + '/' + party, chunk_file)
				chunk.export(out_file, format="wav")

				f = sf.SoundFile(out_file)
				totalFile += 1
				audioDuration = len(f) / f.samplerate

				# if file less than 3 sec or value of remove_file_sec then remove that chunk file
				if audioDuration < remove_file_sec:
					os.remove(out_file)
					# print('==> removed %s\n' % out_file)
					removeCount += 1
				else:
					# import pdb
					# pdb.set_trace()
					as_id = str(datetime.timestamp(datetime.now()))
					as_id = as_id.replace('.', '')
					as_id = as_id.ljust(16, '0')
					exist_segment_data = db_manager.exist_audio_segment_data(new_file_name, file_index, brand_name, party)
					if not exist_segment_data:
						segment_data = {
							'as_id': as_id,
							'callid': new_file_name,
							'segment_id': file_index,
							'supervisor_id': '',
							'user_id': '',
							'audio_gender': '',
							'audio_emotion': '',
							'audio_duration': round(audioDuration),
							'text_bangla': '',
							'text_english': '',
							'brand_name': brand_name,
							'party': party,
							'status': 'N'
						}
						segment_id = db_manager.insert_segment_data(segment_data)
						if segment_id == -1:
							log_file('error => insert_segment_data')

						file_index += 1
		else:
			log_file(path)

	except Exception as e:
		log_file(path+" Error: %s" % str(e))

# os.system("unison")
# print('Total File: %d\n' %totalFile)
# print('Total Removed: %d\n\n' %removeCount)

