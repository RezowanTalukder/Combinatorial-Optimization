#include<bits/stdc++.h>

using namespace std ;

#define m 1000

string a,b ,ans = "" ;

int lenA,lenB,dp[m][m];
bool visited[m][m] ;

int calLCS(int i,int j)
{
    if(a[i]=='\0' || b[j]=='\0') return 0 ;
    if(visited[i][j]) return dp[i][j] ;

    int ans = 0 ;

    if(a[i]==b[j])ans = 1+calLCS(i+1,j+1) ;
    else {
        int val1 = calLCS(i+1,j) ;
        int val2 = calLCS(i,j+1) ;
        ans = max(val1,val2) ;
    }

    visited[i][j] = 1 ;
    dp[i][j] = ans ;

    return dp[i][j] ;
}

void printLCS(int i,int j)
{
    if(a[i]=='\0' || b[j]=='\0'){
        cout<<"first LCS : "<<ans<<endl ;
        ans="" ;
        return ;
    }
    if(a[i]==b[j]){
            ans+=a[i] ;
            printLCS(i+1,j+1) ;
    }
    else {
        if(dp[i+1][j]>dp[i][j+1]) printLCS(i+1,j) ;
        else printLCS(i,j+1) ;
    }
}

void printAllLCS(int i,int j)
{
    if(a[i]=='\0' || b[j]=='\0'){
        cout<<ans<<endl ;
        return ;
    }

    if(a[i]==b[j]){
        ans+=a[i] ;
        printAllLCS(i+1,j+1) ;
        ans.erase(ans.end()-1) ;
    }
    else{
        if(dp[i+1][j]>dp[i][j+1])printAllLCS(i+1,j) ;
        else if(dp[i][j+1]>dp[i+1][j])printAllLCS(i,j+1) ;
        else{
            printAllLCS(i+1,j) ;
            printAllLCS(i,j+1) ;
        }
    }
}

int main()
{
    cin>>a>>b ;
    lenA = a.length() ;
    lenB = b.length() ;

    cout<<calLCS(0,0)<<endl ;
    printLCS(0,0) ;
    printAllLCS(0,0) ;

    return 0 ;
}
