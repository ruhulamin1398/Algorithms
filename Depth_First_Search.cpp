#include<bits/stdc++.h>
using namespace std;
vector<int>adj[100];
int seen[100],dis[100],en[100],n,e,Time;
void DFS(int u)
{
    if(seen[u]==1)
        return;
        cout<<u<<" ";
    seen[u]=1;
    dis[u]=++Time;
    for(int i=0; i<adj[u].size(); i++)
    {
        DFS(adj[u][i]);
    }
    en[u]=++Time;
}
int main()
{
    int a,b;
    cin>>n>>e; ///n=node,e=edge
    for(int i=0; i<e; i++)
    {
        cin>>a>>b;
        adj[a].push_back(b); ///udirected graph
        adj[b].push_back(a);
    }
    cout<<"node visiting sequence : ";
    for(int i=1; i<=n; i++)
        if(!seen[i])
            DFS(i);
    cout<<endl;
    cout<<"starting time  : ";
    for(int i=1; i<=n; i++)
        cout<<dis[i]<<" ";
    cout<<endl;
    cout<<"finishing time : ";
    for(int i=1; i<=n; i++)
        cout<<en[i]<<" ";
    return 0;
}
/*
input :
8 7
1 3
1 4
1 5
5 3
5 7
2 8
8 6
output :
node visiting sequence : 1 3 5 7 4 2 8 6
starting time  : 1 11 2 8 3 13 4 12
finishing time : 10 16 7 9 6 14 5 15
*/
