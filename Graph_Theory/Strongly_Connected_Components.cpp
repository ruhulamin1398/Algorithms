#include<bits/stdc++.h>
using namespace std;
vector<int>v[100],vi[100];
vector<string>va;
int seen[100];
stack<int>s;
void newDFS(int u)
{
    if(seen[u]==1)
        return ;
    cout<<va[u]<<" ";
    seen[u]=1;
    for(int i=0; i<vi[u].size(); i++)
        newDFS(vi[u][i]);
}
void DFS(int u)
{
    if(seen[u]==1)
        return ;
    seen[u]=1;
    for(int i=0; i<v[u].size(); i++)
        DFS(v[u][i]);
    s.push(u);
}
int main()
{
    int n,m;
    cin>>n>>m;
    string s2,s1;
    map<string,int>ma;
    int sz=1;
    while(m--)
    {
        cin>>s1>>s2;
        if(!ma[s1])
        {
            va.push_back(s1);
            ma[s1]=sz++;
        }
        if(!ma[s2])
        {
            va.push_back(s2);
            ma[s2]=sz++;
        }
        v[ma[s1]-1].push_back(ma[s2]-1);
        vi[ma[s2]-1].push_back(ma[s1]-1);
        s1.clear(), s2.clear();
    }
    for(int i=0; i<n; i++)
        if(!seen[i])
            DFS(i);
    for(int i=0; i<=n; i++)
        seen[i]=0;
    cout<<endl<<"SCC component :"<<endl;
    while(!s.empty())
    {
        int t=s.top();
        if(!seen[t])
        {
             newDFS(t);
             cout<<endl;
        }
        s.pop();
    }
}
/**
input :
5 6
Ben Alexander
Alexander Dolly
Dolly Ben
Dolly Benedict
Benedict Dolly
Alexander Aaron

output :
SCC component :
Ben Dolly Alexander Benedict (strongly connected graph)
Aaron

input :
5 5
Ben Alexander
Alexander Dolly
Ben Dolly
Dolly Benedict
Alexander Aaron

output : (no strongly connected graph)
Ben
Alexander
Aaron
Dolly
Benedict
**/
