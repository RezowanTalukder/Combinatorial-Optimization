#include<bits/stdc++.h>

using namespace std ;

int dp[100][1000] ;
int N ,*cost,*weight ;

int knapsak(int i,int w,int CAP)
{
    if(i>=N)return 0 ;
    if(dp[i][w]!=-1) return dp[i][w] ;

     int ret1 , ret2 ;

    if(w+weight[i] <=CAP){
        ret1 = cost[i]+knapsak(i+1,w+weight[i],CAP) ;
    }
    else {
        ret1 = 0 ;
    }

    ret2 = knapsak(i+1,w,CAP) ;

    dp[i][w] = max(ret1,ret2) ;
    return dp[i][w] ;

}

int main()
{
    int test ;
    cin>>test ;
    while(test--)
    {
        cin>>N ;
        cost = new int[N] ;
        weight = new int[N] ;
        memset(dp,-1,sizeof dp) ;

        for(int i=0 ;i<N ;i++){
            int w,p ;
            cin>>p>>w ;
            cost[i] = p ;
            weight[i] = w ;
        }

        int t,ans = 0  ;
        cin>>t ;
        while(t--){
            int CAP ;
            cin>>CAP ;
            ans+=knapsak(0,0,CAP) ;
        }
        cout<<ans<<endl ;
    }

    return 0 ;
}
