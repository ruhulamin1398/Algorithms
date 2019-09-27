#include<bits/stdc++.h>
using namespace std;
vector<int>v[100];
int seen[100],e,n,level[100],component,a,b;
int BFS(int start,int s)
{
    queue<int>q;
    q.push(start);
    seen[start]=s;
    level[start]=1;
    while(!q.empty())
    {
        int x=q.front();
        cout<<x<<" ";
        int len=v[x].size();
        for(int i=0; i<len; i++)
        {
            if(seen[v[x][i]]==0)
            {
                q.push(v[x][i]);
                seen[v[x][i]]=s;
                level[v[x][i]]=level[x]+1;
            }
        }
        q.pop();
    }
}
int main()
{
    cin>>n>>e; ///n=node,e=edge
    for(int i=0; i<e; i++)
    {
        a,b;
        cin>>a>>b;
        v[a].push_back(b); ///undirected graph
        v[b].push_back(a);
    }
    cout<<"node visiting sequence : ";
    for(int u=1; u<=n; u++)
        if(!seen[u])
        {
            component++; ///how many component of Graph
            BFS(u,u);
        }
    cout<<endl<<"node lavel : ";///dif digit means dif level or color
    for(int i=1; i<=n; i++)  ///2 6 8 dif graph
        cout<<level[i]<<" ";
    cout<<endl<<"This Graph has "<<component<<" component"<<endl;
    for(int i=1; i<=2; i++)
    {
        cin>>a>>b;
        if(seen[a]==seen[b]) ///if a and be same component
            cout<<a<<" and "<<b<<" has same component.."<<endl;
        else
            cout<<a<<" and "<<b<<" has diff component.."<<endl;
    }
}
/**
input :
8 7
1 3
1 4
1 5
5 3
5 7
2 8
8 6
3 5
3 8
output :
node visiting sequence : 1 3 4 5 7 2 8 6
node level : 1 1 2 2 2 3 3 2
This Graph has 2 component
3 and 5 has same component..
3 and 8 has diff component..
**/

