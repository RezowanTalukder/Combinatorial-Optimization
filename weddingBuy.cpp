#include<bits/stdc++.h>

using namespace std ;

int M,C,dp[210][21] , price[21][21] ;

int shop(int M_left ,int index)
{
    if(M_left<0) return -1 ;
    if(index==C) return M-M_left ;
    if(dp[M_left][index]!=-1)return dp[M_left][index] ;

    int maxValue = -10000 ;

    for(int i=1 ;i<=price[index][0] ;i++){
        maxValue = max(maxValue,shop((M_left-price[index][i]),index+1)) ;
    }

    dp[M_left][index] = maxValue ;
    return dp[M_left][index] ;
}

int main()
{
    int tc ;
    cin>>tc ;
    while(tc--){

            cin>>M>>C  ;
            for(int i=0 ;i<C ;i++){
                int x ;
                cin>>x ;
                price[i][0] = x ;
                for(int j= 1 ;j<=x ;j++){
                    cin>>price[i][j] ;
                }
            }

            memset(dp,-1,sizeof dp) ;

            int score = shop(M,0) ;

            if(score<0)cout<<"no solution"<<endl ;
            else cout<<score<<endl ;

    }
    return 0 ;
}
