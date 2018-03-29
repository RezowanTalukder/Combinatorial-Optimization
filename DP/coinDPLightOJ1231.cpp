#include<bits/stdc++.h>

using namespace std ;

int amount , dp[10][7490] ,c[5] ={50,250,200,5,100} ;

int coin(int i,int amount)
{
    if(i>=5){
        if(amount==0)return 1 ;
        else return 0 ;
    }

    if(dp[i][amount]!=-1)return dp[i][amount] ;

    int r1 = 0 ,r2=0 ;
    for(int x=0 ;x<3 ;x++){
        if(amount-c[i]>=0)r1 = coin(i,amount-c[i]) ;
    }
    r2 = coin(i+1,amount) ;

    return dp[i][amount] = r1 | r2 ;
}

int main()
{

    memset(dp,-1,sizeof dp) ;

    while(cin>>amount)
    {
        cout<<coin(0,amount)<<endl ;
    }
}

