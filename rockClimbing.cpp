#include<bits/stdc++.h>

using namespace std ;

int dp[10][10] ;
int adj[10][10] ;
int r,c ;

int call(int i,int j)
{
    if(i>=0 && i<r && j>=0 && j<c)
    {
        if(dp[i][j]!=-1) return dp[i][j] ;

        int ret = -1 ;

        ret = max(ret,call(i+1,j-1)) ;
        ret = max(ret,call(i+1,j)) ;
        ret = max(ret,call(i+1,j+1)) ;
        return dp[i][j] = ret ;
    }
    else return 0 ;
}

int main()
{
    memset(dp,-1,sizeof dp) ;
    cin>>r>>c ;
    for(int i=0;i<r ;i++){
        for(int j=0 ;j<c ;j++){
            cin>>adj[i][j] ;
        }
    }
    cout<<call(0,0)<<endl  ;
    return 0 ;
}
