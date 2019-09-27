#include<bits/stdc++.h>
using namespace std;
#define inf INT_MAX
typedef pair<int,int>iPair;
vector<iPair>adj[100];
int n,e;
void MST()
{
    priority_queue< iPair >pq; ///sort first element wise with low first
    vector<int>value(n+1,inf),seen(n+1,0),parent(n+1,-1);
    int source = 1;
    pq.push(make_pair(0,source)),value[source]=0;
    while(!pq.empty())
    {
        int u = pq.top().second;
        pq.pop(),seen[u]=1;
        for(auto x : adj[u])
        {
            int v = x.second,weight=x.first;
            if(!seen[v] && value[v]>weight)
            {
                value[v]=weight;
                parent[v] = u;   // u hoye asce
                pq.push(make_pair(value[v],v));
            }
        }
    }
    int mst=0;
    cout<<"Node connect to MST :"<<endl;
    for(int i=2; i<=n; i++)
    {
        cout<<parent[i]<<" - "<<i<<endl;
        mst+=value[i];
    }
    cout<<"Minimun Spanning Tree : "<<mst;
}

int main()
{
    cin>>n>>e;
    while(e--)
    {
        int u,v,weight;
        cin>>u>>v>>weight;
        adj[u].push_back(make_pair(weight,v));
        adj[v].push_back(make_pair(weight,u));
    }
    MST();
}
/**
input:
4 5
1 2 7
1 4 6
4 2 9
4 3 8
2 3 6
output:
Node connect to MST :
1 - 2
2 - 3
1 - 4
Minimun Spanning Tree : 19

input:
4 5
1 2 7
1 4 6
4 2 5
4 3 8
2 3 6
output:
Node connect to MST :
4 - 2
2 - 3
1 - 4
Minimun Spanning Tree : 17
**/
