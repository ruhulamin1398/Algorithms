#include<bits/stdc++.h>
using namespace std;
int seen[100],cycle;
vector<int>adj[100];
void DFS(int start)
{
    if(seen[start]==1)
    {
        cycle++;
        return ;
    }
    else if(seen[start]==2)
        return ;
    seen[start]=1;
    if(adj[start].size()==0) ///if it has no leaf
        seen[start]=2;
    for(int i=0; i<adj[start].size(); i++)
        DFS(adj[start][i]);
}
int main()
{
    int n,e,a,b;
    cin>>n>>e;
    for(int i=1; i<=e; i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
    }
    DFS(1);
    cout<<"For Directed Graph : "<<cycle;
}
/**
input :
7 10
1 2
1 4
2 3
3 1
4 5
5 3
5 6
6 2
2 7
7 1
output :
Directed Graph : 4
Undirected Graph : 14
**/
