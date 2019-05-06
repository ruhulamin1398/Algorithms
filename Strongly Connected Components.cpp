/**
input :
10 12
1 2
2 3
3 4
4 5
5 2
5 7
7 8
8 9
9 7
8 6
6 10
10 6

output:

SCC 1:	1 
SCC 2:	2 5 4 3 
SCC 3:	7 9 8 
SCC 4:	6 10 

**/


#include<bits/stdc++.h>
using namespace std;
vector<int> forwordGraph[50],reverseGraph[50];
stack<int>st;
vector<bool>visited;
int component=1;

void dfs(int x) {
    visited[x]=true;
    for( int i=0 ; i<forwordGraph[x].size(); i++) {
        if(!visited[forwordGraph[x][i]] )
            dfs(forwordGraph[x][i]);
        st.push(x);
    }

}
void dfs2( int  x) {
    cout<<x<<" ";
    visited[x]=true;
    for(int i=0 ; i<reverseGraph[x].size(); i++) {
        if(!visited[reverseGraph[x][i]])
            dfs2(reverseGraph[x][i]);
    }

}


int main() {
//    freopen("input.txt","r",stdin);
//    freopen("output.txt","w",stdout);

    visited.assign(100,false);
    int v,e;
    cin>>v>>e;
    int a, b ;

    for( int i =1 ; i<=e ; i++) {
        cin>>a>>b;
        forwordGraph[a].push_back(b);
        reverseGraph[b].push_back(a);
    }
    for(int i=1 ; i<=v ; i++) {
        if(!visited[i]) {
            dfs(i);
        }
    }
    visited.assign(v+2,false);

    while(!st.empty()) {

        if(!visited[st.top()] ) {
            cout<<endl<<"SCC "<<component++<<":\t";
            dfs2(st.top());
        }
        st.pop();
    }
    return 0;
}
