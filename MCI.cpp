#include<bits/stdc++.h>

using namespace std ;

#define N 15

int main()
{
    int arr[N] ;
    for(int i=0 ;i<N ;i++){
        cin>>arr[i] ;
    }

    int temp=0 ,ans =0  ;
    int cur_sum = 0 ;

    for(int i=0 ;i<N ;i++)
    {
        cur_sum+=arr[i] ;

        if(temp<cur_sum){
            temp = cur_sum ;
        }
        if(cur_sum<0){
            cur_sum = 0 ;
        }
        if(ans<temp) ans = temp ;
    }
    cout<<temp<<endl ;
}
