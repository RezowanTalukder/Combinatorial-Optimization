#include<bits/stdc++.h>

using namespace std ;
int main()
{
    string str1[1001] ;
    int n,x= 0 ;

    cin>>n ;
    getchar() ;
    for(int i=1 ;i<n+1 ;i++){
        getchar() ;
        getline(cin,str1[i]) ;
        if(str1[i]=="\n")break ;
        x++ ;
    }
    for(int i=0 ;i<x ;i++){
        for(int j = i ; j<x ; j++){
            int l = str1[i].length() ;
            int m = str1[j].length() ;
            if(!(lexicographical_compare(str1[i],str1[i]+l,str1[j],str1[j]+m)){
                string temp = str1[i] ;
                str1[i] = str1[j] ;
                str1[j] = temp ;
            }
        }
    }
    for(int i=0 ;i<x ;i++){
        cout<<str1[i]<<endl ;
    }
    return 0 ;
}
