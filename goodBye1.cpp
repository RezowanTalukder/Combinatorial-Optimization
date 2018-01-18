#include<bits/stdc++.h>

using namespace std ;

int main()
{
    string str ;
    cin>>str ;
    int len = str.length() ;
    int cou = 0 ;
    for(int i=0 ;i<len ;i++){
        switch(str[i]){
            case '1' : cou++ ; break ;
            case '3' : cou++ ;break ;
            case '5' : cou++ ; break ;
            case '7' : cou++ ;break ;
            case '9' : cou++ ; break ;
            case 'a' : cou++ ;break ;
            case 'e' : cou++ ; break ;
            case 'i' : cou++ ;break ;
            case 'o' : cou++ ; break ;
            case 'u' : cou++ ;break ;
        }
    }
    cout<<cou<<endl ;
    return 0 ;
}
