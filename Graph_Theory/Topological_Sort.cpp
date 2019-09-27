#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m,a,b;
    cin>>n>>m;
    vector<int>in(n+1),out[n+1];
    for(int i=1; i<=m; i++)
    {
        cin>>a>>b;
        out[a].push_back(b);
        in[b]++;
    }
    queue<int>q;
    for(int i=1;i<=n;i++)
        if(!in[i])
        q.push(i);
    while(!q.empty())
    {
        int x = q.front();
        cout<<x<<" ";
        for(int i=0;i<out[x].size();i++)
        {
            in[out[x][i]]--;
            if(!in[out[x][i]])
                q.push(out[x][i]);
        }
        q.pop();
    }
    return 0;
}
/**
input :
5 4
1 2
2 3
1 3
1 5

output :
1 4 2 5 3
**/
