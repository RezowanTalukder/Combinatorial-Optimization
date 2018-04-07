#include<bits/stdc++.h>

using namespace std ;

int dp[100][100] ;

int nCr(int n,int r)
{
    if(n==r)return 1 ;
    if(r==1) return n ;
    if(dp[n][r]!=0)return dp[n][r] ;
    else {
        dp[n][r] = nCr(n,r-1)+nCr(n-1,r-1) ;
        return dp[n][r] ;
    }
}

int main()
{
    int n,r ;
    memset(dp,0,sizeof(dp)) ;

    while(cin>>n>>r)
    {
        // n<r hole break ;
        cout<<nCr(n,r)<<endl ;
    }

    return 0 ;
}
