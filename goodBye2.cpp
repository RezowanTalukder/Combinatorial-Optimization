#include<bits/stdc++.h>

using namespace std ;

int main()
{
    int n,r ;
    int x[1001] ;
    float y[1001] ;

    cin>>n>>r ;
    for(int i=0 ;i<n ;i++){
        cin>>x[i] ;
        y[i] = -1 ;
    }
    y[0] = r ;
    for(int i=1 ;i<n ;i++){
        int flag = 0 ;
        for(int j=0 ;j<i ; j++){
            if(abs(x[i]-x[j])<=(2*r)){
                float b ;
                int sq = 4*r*r-(x[j]-x[i])*(x[j]-x[i]) ;
                float sqr = sqrt(sq) ;
                b=(float)y[j] + sqr ;
                if(b>y[i]) y[i] = b ;
                flag = 1 ;
            }
        }
        if(flag==0)y[i] = r ;
    }
    for(int i=0 ;i<n ;i++){
        cout<<fixed<<setprecision(6)<<y[i]<<" " ;
    }
    return 0 ;
}
