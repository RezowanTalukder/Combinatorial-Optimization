#include<bits/stdc++.h>

using namespace std ;
#define M 100

int row[M] ,col[M] , dp[M][M] ;
bool visited[M][M] ;

int matrixChain(int beg,int endd)
{
    if(beg>=endd) return 0 ;
    if(visited[beg][endd]) return dp[beg][endd] ;

    int ans = 5555 ;

    for(int k=beg ;k<endd ;k++){
        int left  =  matrixChain(beg,k) ;
        int right = matrixChain(k+1,endd) ;
        int total = left + right + row[beg]*col[k]*col[endd] ;
        ans = min(ans,total) ;
    }
    dp[beg][endd] = ans ;
    visited[beg][endd] = true ;

    return dp[beg][endd] ;
}

int main()
{
    int n ;
    memset(dp,-1,sizeof dp) ;
    memset(visited,false,sizeof visited) ;
    cin>>n ;
    cin>>row[0] ;
    for(int i=1 ;i<n-1 ;i++){
        int a ;
        cin>>a ;
        col[i-1] = a ;
        row[i] = a ;
    }
    cin>>col[n-2] ;
/*
    for(int i=0 ;i<n-1 ;i++){
        cout<<row[i]<<"  "<<col[i]<<endl ;
    }
*/

    cout<<matrixChain(0,n-1)<<endl ;
    return  0 ;

}
