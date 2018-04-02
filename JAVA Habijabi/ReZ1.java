
package rez1;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Scanner;


public class ReZ1 {

   
    public static void main(String[] args) throws IOException {
        try {
            LZWCompression lzw = new LZWCompression();

            Scanner input = new Scanner(System.in);

            System.out.println("Enter the name of your (input.txt) file : ");

            String str = input.nextLine();

            File file = new File(str);

            Scanner fileScanner = new Scanner(file);

            String line = "";

            while (fileScanner.hasNext()) {
                line = fileScanner.nextLine();
                System.out.println("Contents of your file being compressed: \n"
                        + line);
            }
            
            lzw.compress(str);
            
            System.out.println("\nCompression of your file is complete!");
            System.out.println("Your new file is named: " + str.concat(".lzw"));
            
        } catch (FileNotFoundException e) {
            System.out.println("File was not found!");
        }
    }
    
}
