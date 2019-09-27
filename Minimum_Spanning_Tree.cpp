#include<bits/stdc++.h>
using namespace std;
int parent[100];
struct Data
{
    int u,v,cost;
} node[100];

bool cmp(Data a,Data b)
{
    if(a.cost<b.cost)
        return 1;
    return 0;
}

int find_parent(int x)
{
    if(parent[x]==x)
        return x;
    else
        return parent[x]=find_parent(parent[x]);
}

int main()
{
    int n,e,u,v,cost=0;
    vector<Data>ans;
    cin>>n>>e;
    for(int i=0; i<e; i++)
        cin>>node[i].u>>node[i].v>>node[i].cost;
    cout<<endl;
    sort(node,node+e,cmp);
    for(int i=1; i<=n; i++)
        parent[i]=i;
    int cnt=0;
    for(int i=0; i<e; i++)
    {
        int u=find_parent(node[i].u);
        int v=find_parent(node[i].v);
        if(u!=v)
        {
            parent[u]=v;
            cnt++;
            cost+=node[i].cost;
            ans.push_back({node[i].u,node[i].v,node[i].cost});
            if(cnt==(n-1))
                break;
        }
    }
    cout<<"Minimum Spanning Tree "<<endl;
    for(int i=0; i<ans.size(); i++)
        cout<<ans[i].u<<" and "<<ans[i].v<<" with cost "<<ans[i].cost<<endl;
    cout<<"Minimum cost "<<cost;
}

/**
6 7
1 2 1
2 4 4
2 3 3
3 6 2
1 5 6
4 6 1
3 5 4

Minimum Spanning Tree
1 and 2 with cost 1
4 and 6 with cost 1
3 and 6 with cost 2
2 and 3 with cost 3
3 and 5 with cost 4
Minimum cost 11

7 11
1 2 7
1 4 5
2 3 8
2 4 9
4 6 6
5 6 8
2 5 7
3 5 5
5 7 9
6 7 11
4 5 15

Minimum Spanning Tree
1 and 4 with cost 5
3 and 5 with cost 5
4 and 6 with cost 6
1 and 2 with cost 7
2 and 5 with cost 7
5 and 7 with cost 9
Minimum cost 39

**/
