#include<bits/stdc++.h>
#include<map>
using namespace std ;

map<string,int> mp ;
mp<string,int> :: iterator it ;
string sss = "abcdefghijklmnoqrstuvwxyz" ;
int num = 1 ;
string str ;

void lenOne()
{
    for(int i=0 ; i<26 ;i++){
        string temp = sss[i] ;
        mp[] = num++ ;
    }
}

void lenTwo()
{
    lenOne() ;
    for(int i=0 ; i<26 ;i++){
        for(int j=i+1 ; j<26 ;j++){
            string temp = sss[i] ;
            string temp1 = sss[j] ;
            string temp3 = temp+temp1 ;
            mp[temp3] = num++ ;
        }
    }
}

void lenThree()
{
    lenOne() ;
    lenTwo() ;
    for(int i=0 ; i<26 ;i++){
        for(int j=i+1 ; j<26 ;j++){
            for(int k=j+1 ; k<26 ; k++){
                string temp = sss[i] ;
                string temp1 = sss[j] ;
                string temp3 = sss[k] ;
                string temp4 = temp+temp1 +temp3;
                mp[temp4] = num++ ;
            }
        }
    }
}

void lenFour()
{
    lenOne() ;
    lenTwo() ;
    lenThree() ;
    for(int i=0 ; i<26 ;i++){
        for(int j=i+1 ; j<26 ;j++){
            for(int k=j+1 ; k<26 ; k++){
                for(int l=k+1 ;l<26 ;l++){
                    string temp = sss[i] ;
                    string temp1 = sss[j] ;
                    string temp3 = sss[k] ;
                    string temp4 = sss[l] ;
                    string temp5 = temp+temp1 +temp3 +temp4 ;
                    mp[temp5] = num++ ;
                }
            }
        }
    }
}

void lenFive()
{
    lenOne() ;
    lenTwo() ;
    lenThree() ;
    lenFour() ;
    for(int i=0 ; i<26 ;i++){
        for(int j=i+1 ; j<26 ;j++){
            for(int k=j+1 ; k<26 ; k++){
                for(int l=k+1 ;l<26 ;l++){
                    for(int m=l+1 ;m<26 ;m++){
                        string temp = sss[i] ;
                        string temp1 = sss[j] ;
                        string temp3 = sss[k] ;
                        string temp4 = sss[l] ;
                        string temp5 = sss[m] ;
                        string temp6 = temp+temp1 +temp3 +temp4 +temp5 ;
                        mp[temp6] = num++ ;
                    }
                }
            }
        }
    }
}

void print()
{
    it = mp.find(str) ;
    if(it==mp.end())cout<<"0"<<endl ;
    else cout<<it->second()<<endl ;
}

int main()
{
    while(cin>>str){
        int length ;
        len = str.length() ;
        switch(len){
            case 1 : lenOne() ; break ;
            case 2 : lenTwo() ;break ;
            case 3 : lenThree() ; break ;
            case 4 : lenFour() ; break ;
            case 5 : lenFive() ; break ;
            default : cout<<"0"<<endl ; return 0 ;
        }
        print();
    }
    return 0 ;
}
