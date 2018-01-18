#include<iostream>
#include<queue>

using namespace std ;

int main()
{
    queue <int> que  ;
    int n ;
    while(cin>>n){
        int  ultimate_sum = 0 ;
        for(int i=1 ; i<=n ;i++){
        que.push(i) ;
        }
        int sum = 1 ;
        que.pop() ;
        for(int i = 0  ;i<n-1 ;i++){
            sum+=que.front() ;
            ultimate_sum+=sum ;
            sum = ultimate_sum ;
            que.pop() ;
        }
        cout<<ultimate_sum<<endl ;
    }
    return 0 ;
}
