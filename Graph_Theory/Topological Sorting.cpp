#include<bits/stdc++.h>
using namespace std;
int main()
{
    int node, edge;
    cin>>node>>edge;
    vector<int >in,out[node+1];

    for( int i =0 ; i<=node ; i++)
        in.push_back(0);
    for( int i =1 ; i<=node ; i++)
    {
        int a,b;
        cin>>a>>b;
        in[b]++;
        out[a].push_back(b);
    }
    queue<int > q;
    for( int i =1 ; i<=node ; i++)
    {
        if(in[i]==0)
            q.push(i);
    }
    while(! q.empty())
    {
        int f=q.front();
        cout<<q.front()<<" ";
        for( int j=0 ; j<out[f].size() ; j++)
        {
            in[out[f][j]]--;
            if( in[out[f][j]]==0 )
                q.push(out[f][j]);
        }
            q.pop();
    }
    return 0 ;
}
