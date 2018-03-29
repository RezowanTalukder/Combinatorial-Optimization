#include<bits/stdc++.h>

using namespace std ;
int *c ,N ;
int dp[30][10000] ;

int coin(int i,int amount)
{
    if(i>=N){
        if(amount==0)return 1 ;
        else return 0 ;
    }

    if(dp[i][amount]!=-1)return dp[i][amount] ;

    int r1 = 0 , r2 = 0 ;

    if(amount-c[i]>=0)r1 = coin(i+1,amount-c[i]) ;
    r2 = coin(i+1,amount) ;

    return dp[i][amount] = r1 | r2 ;
}

int main()
{
    freopen("x.txt","r",stdin) ;

    int test ;
    cin>>test ;
    while(test--){
        memset(dp,-1,sizeof dp) ;
        cin>>N ;
        c = new int[N] ;
        int sum = 0 ;
        for(int i=0 ;i<N ;i++){
            cin>>c[i] ;
            sum+=c[i] ;
        }

        int high,low ;

        if(sum%2==1){
            high = sum/2 + 1 ;
            low = sum/2 ;
        }
        else low = high = sum/2 ;

        for(int i=low ,j = high ;i>0 && j<sum ;i--,j++){

            memset(dp,-1,sizeof dp) ;
            int h = coin(0,j) ;

            memset(dp,-1,sizeof dp) ;

            int l = coin(0,i) ;

            if(h==1 && l==1){
                cout<<(j-i)<<endl ;
                break ;
            }
        }

    }

    return 0 ;
}
