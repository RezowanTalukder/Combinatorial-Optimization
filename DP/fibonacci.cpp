#include<bits/stdc++.h>

using namespace std ;

int dp[100] ;

int fibo(int n)
{
    if(n==0) return 0 ;
    if(n==1) return 1 ;
    if(dp[n]!=0)return dp[n] ;
    else {
        dp[n] = fibo(n-1)+fibo(n-2) ;
        return dp[n] ;
    }
}

int main()
{
    int n ;
    memset(dp,0,sizeof(dp)) ;
    while(cin>>n){
        cout<<fibo(n)<<endl ;
    }

}
