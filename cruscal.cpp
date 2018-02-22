#include<bits/stdc++.h>

using namespace std ;

typedef pair<int,int>pii ;

int parent[100] ;

vector< pair<int,pii> > V ;
vector< pair<int,pii> > T ;

int findSet(int i)
{
    if(i==parent[i])    return i ;
    else return findSet(parent[i]) ;
}

void union_set(int u , int v)
{
    parent[v] = u ;
}

void cruskal()
{
    int uP,vP;

    for(int i=0 ;i<V.size() ;++i){
        uP = findSet((V[i].second).first) ;
        vP = findSet((V[i].second).second) ;
        if(uP!=vP){
            T.push_back(V[i]) ;
            union_set(uP,vP) ;
        }
    }
    for(int i =0 ;i<T.size() ;++i){
        cout<<T[i].second.first<<" "<<T[i].second.second<<" "<<T[i].first<<endl ;
    }
}

int main()
{


    int edges ;
    cin>>edges ;
    while(edges--)
    {
        int u,v,w ;
        cin>>u>>v>>w ;
        V.push_back(make_pair(w,pii(u,v))) ;
    }

    sort(V.begin(),V.end()) ;

    for(int i=0 ;i<100 ;i++) parent[i] = i ;

    cruskal() ;

    return 0 ;
}


/*
16
0 5 54
0 4 80
5 3 74
3 7 29
7 6 68
6 4 93
0 2 47
2 1 55
1 7 79
5 2 75
2 3 88
1 3 31
2 4 23
2 6 66
1 6 74
4 2 32

*/
