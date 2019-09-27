#include<bits/stdc++.h>
using namespace std;
vector<int>adj[10];
queue<int>q;
int seen[100],dis[100];
void BFS(int u,int v)
{
    seen[u]=1;
    dis[u]=0;
    q.push(u);
    while(!q.empty())
    {
        int temp;
        int s=q.front();
        for(int i=0; i<adj[s].size(); i++)
        {
            temp=adj[s][i];
            if(!seen[temp])
            {
                q.push(temp);
                seen[temp]=1;
                int d = dis[s]+1;
                if(dis[temp]>d)
                    dis[temp]=d;
            }
            else
            {
                int d = dis[s]+1;
                if(dis[temp]>d)
                    dis[temp]=d;
            }
            if(temp==v)
            {
                cout<< dis[temp]<<endl;
                return ;
            }
        }
        q.pop();
    }
}
int main()
{
    int a,b;
    for(int i=1; i<=7; i++)
    {
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i=0; i<19; i++)
        dis[i]=99;
    for(int i=1; i<=2; i++)
    {
        cin>>a>>b;
        BFS(a,b);
    }
}

/**
1 2
1 5
1 3
2 6
4 6
4 5
3 5

1 4
2
1 5
1
**/
