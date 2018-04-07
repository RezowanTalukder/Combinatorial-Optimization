//Time Limit exit


#include<bits/stdc++.h>

using namespace std ;

int *dp ;

int a, b, c, d, e, f;

int fn( int n ) {
            for(int i=0 ;i<=n ;i++)
            {
                    if( n == 0 ) {
                dp[n]= a;continue ;
            }
            if( n == 1 ) {
                dp[n]= b;continue ;
            }
            if( n == 2 ) {
                dp[n]= c;continue ;
            }
            if( n == 3 ) {
                dp[n]= d;continue ;
            }
            if( n == 4 ) {
                dp[n]= e;continue ;
            }
            if( n == 5 ) {
                dp[n]= f;continue ;
            }

            dp[n]=fn(n-1) + fn(n-2) + fn(n-3) + fn(n-4) + fn(n-5) + fn(n-6) ;
    }

    return dp[n] ;
}
int main() {
    int n, caseno = 0, cases;
    scanf("%d", &cases);
    while( cases-- ) {
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &e, &f, &n);
        dp = new int[n+2] ;
        //for(int i=0 ;i<=n ;i++)dp[n]=-1 ;
        printf("Case %d: %d\n", ++caseno, fn(n) % 10000007);
    }
    return 0 ;
}
