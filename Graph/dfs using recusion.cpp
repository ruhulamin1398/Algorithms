
#include<bits/stdc++.h>
using namespace std;
vector<int>arr[101];

int seen[1002];
void dfs(int u ) {
    cout<<u<<" ";
    seen[u]=1;

    for(int i =0 ; i<arr[u].size(); i++) {

            int data= arr[u][i];
            if(!seen[data])
            {
                dfs(data);
            }
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

    for( int i =1 ; i<=n ; i++) {
        if(!seen[i]) {
            dfs(i);
        }
    }
}
