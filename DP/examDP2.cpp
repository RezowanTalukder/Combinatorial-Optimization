#include<bits/stdc++.h>

using namespace std ;

int amount , dp[5][30001] ,c[5] ={50,25,10,5,1} ;

int coin(int i,int amount)
{
    if(i>=5){
        if(amount==0)return 1 ;
        else return 0 ;
    }

    if(dp[i][amount]!=-1)return dp[i][amount] ;

    int r1 = 0 ,r2=0 ;

    if(amount-c[i]>=0)r1 = coin(i,amount-c[i]) ;
    r2 = coin(i+1,amount) ;

    return dp[i][amount] = r1 + r2 ;
}


int main()
{

    memset(dp,-1,sizeof dp) ;

    while(cin>>amount)
    {
        cout<<"There are "<<coin(0,amount)<<" ways to produce "<<amount<<" cents."<<endl ;
    }
}

