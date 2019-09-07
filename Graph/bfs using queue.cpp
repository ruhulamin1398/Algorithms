#include<bits/stdc++.h>
using namespace std;

vector<int>arr[101];
queue<int>q;
int seen[1002];
int level[101];
void bfs(int u ) {

    cout<<u<<" ";
    seen[u]=1;
    q.push(u);
    int l=1;
    level[u]=l;
    while(!q.empty()) {
        int data =q.front();
        l++;
        for(int i =0 ; i<arr[data].size(); i++) {
                int temp=arr[data][i];
            if(seen[temp]==0) {
                    level[temp]=l;
                seen[temp]=1;
                q.push(temp);
                cout<<temp<<" ";
            }
        }
        q.pop();
    }
}

int main() {
    int n, e ;
    cin>>n>>e;
    int a, b ;

    for( int i =0 ; i<e ; i++) {
        cin>>a>>b;
        arr[a].push_back(b);
    }
    for( int i =1 ; i<n ; i++) {
        if(!seen[i]) {
            bfs(i);
        }
    }


cout<<endl"level"<<endl;
for( int i=1 ; i<=n ; i++)
cout<<level[i]<<" ";


}
