#include<bits/stdc++.h>
using namespace std;

#define inf         INT_MAX
#define pii         pair<int , int>
#define pb          push_back
#define mp          make_pair


int n, e ,u,v;
vector<pii> adj[10001];
priority_queue< pii, vector<pii>,greater<pii> > pq;

    vector<int> parrent(10000,-1);
    vector<int> value(10000,inf);
    vector<bool> visited(10000,false);





void primeMST() {



    int startNode=0;
    pq.push(mp(0,startNode));

    value[startNode]=0;


    while(! pq.empty()) {
        int u= pq.top().second;
        pq.pop();
        visited[u]=true;

        for( auto x: adj[u] ){
            v= x.first;
            int weight = x.second ;
            if( visited [v]== false && value[v]>weight){
                value[v]= weight ;
                parrent[v]= u ;
                pq.push(mp(value[v],v));
            }
        }

    }





}


void printMST(){

for( int i =0 ; i<n ; i++){
    cout<<parrent[i]<<" - "<<i<<endl;
}
}



int main() {
    cin>>n>>e;

    while(e--) {
        int a, b, cost;
        cin>>a>>b>>cost;
        adj[a].pb(mp(b,cost));
        adj[b].pb(mp(a,cost));
    }

    primeMST();
    printMST();






    return 0 ;
}
