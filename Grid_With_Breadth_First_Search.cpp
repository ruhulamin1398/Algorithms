#include<bits/stdc++.h>
#define M pair<int,int>
using namespace std;
int fx[]= {1,-1,0,0},fy[]= {0,0,1,-1};
int seen[5][5],arr[5][5],ans=0,row,col;
void bfs(int x,int y)
{
    queue<M>q;
    q.push(M(x,y));
    seen[x][y]=1;
    while(!q.empty())
    {
        M top=q.front();
        q.pop();
        for(int k=0; k<4; k++)
        {
            x=top.first+fx[k];
            y=top.second+fy[k]; //Neighbor cell [tx][ty]
            if(x>=0 && x<col && y>=0 && y<row && (arr[x][y]==1||arr[x][y]==5) && seen[x][y]==0)
            { //if valid or not valid
                seen[x][y]=1;
                q.push(M(x,y)); //Pushing a new pair in the queue
                ans++;
            }
        }
    }
}
int main()
{
    cin>>row>>col;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cin>>arr[i][j];
        }
    }
    bfs(0,0);
    cout<<ans;
}
/*
4 4
1 0 0 0
1 1 0 0
0 1 0 0
0 1 1 5
*/
