#include<bits/stdc++.h>
using namespace std;

vector<int>arr[101];
stack<int>s;
int seen[1002];
int level[101];
void dfs(int u ) {


    seen[u]=1;
    s.push(u);

    while(!s.empty()) {
        int data =s.top();
        cout<<data<<" ";
        s.pop();

        for(int i =0 ; i<arr[data].size(); i++) {
            int temp=arr[data][i];
            if(seen[temp]==0) {
                seen[temp]=1;
                s.push(temp);
            }
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

    for( int i =1 ; i<n ; i++) {
        if(!seen[i]) {
            dfs(i);
        }
    }






}
