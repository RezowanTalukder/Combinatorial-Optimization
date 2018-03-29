#include<bits/stdc++.h>

using namespace std ;

int weight[100],CAP ,cost[100],x ;

int Knapsak(int i,int w)
{
    int profit1,profit2 ;
    if(i>x)return 0 ;

    if(w+weight[i]<=CAP){
        profit1 = cost[i]+Knapsak(i+1,w+weight[i]) ;
    }
    else profit1 = 0 ;

    profit2 = Knapsak(i+1,w) ;

    return max(profit1,profit2) ;

}

int main()
{
    cin>>x>>CAP ;
    for(int i=1 ;i<=x ;i++){
        cin>>weight[i]>>cost[i] ;
    }
    cout<<Knapsak(1,0)<<endl ;
    return 0 ;
}
