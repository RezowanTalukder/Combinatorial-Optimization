#include<bits/stdc++.h>

using namespace std ;

void frickles() ;
double point[100][2] ;
int n ;
double sum ;

void frickles()
{
    double ax , min ;
    double dist[100] ;
    bool intree[100] ;
    memset(intree,0,sizeof(intree)) ;
    for(int i=0 ;i<100 ;i++)dist[i] = 1000001.0 ;

    int v = 0 ;
    dist[0] = 0 ;
    sum =0  ;

    while(!intree[v]){
        intree[v] = 1 ;
        sum+=dist[v] ;

        for(int i=0 ;i<n ;i++){
            if(! intree[i]){
                double x= point[v][0]-point[i][0] ;
                double y = point[v][1]-point[i][1] ;
                ax = sqrt(x*x + y*y) ;
                if(ax<dist[i])dist[i] = ax ;
            }
        }

        v=0 ;
        min = 10000001.0 ;

        for(int i=0 ;i<n ;i++){
            if(!intree[i]){
                if(dist[i]<min){
                    v=i ;
                    min = dist[i] ;
                }
            }
        }
    }
    printf("%.2f\n",sum) ;
}

int main()
{
    int T ;
    double a, b ;
    cin>>T ;getchar() ;
    for(int i=0 ;i<T ;i++){
        getchar() ;
        cin>>n ;
        for(int j= 0 ;j<n ;j++){
            cin>>a>>b ;
            point[j][0] = a ;
            point[j][1] = b ;
        }
    }

    frickles() ;

    return 0 ;
}
