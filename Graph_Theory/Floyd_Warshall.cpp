#include<bits/stdc++.h>
using namespace std;
#define mx 100
int main()
{
    int matrix[5][5];
    for(int i=0; i<5; i++)
        for(int j=0; j<5; j++)
        {
            if(i==j)
                matrix[i][j]=0;
            else
                matrix[i][j] = mx;
        }
    int node,edge;
    cin>>node>>edge;
    while(edge--)
    {
        int u,v,cost;
        cin>>u>>v>>cost;
        matrix[u][v]=cost;
    }
    for (int k = 1; k <= node; k++)
        for (int i = 1; i <= node; i++)
            for (int j = 1; j <= node; j++)
                matrix[i][j] = min(matrix[i][j], matrix[i][k] + matrix[k][j]); ///distance i to k + k to j -> that mean i to j by k..

    for(int i=1; i<5; i++)
    {
        for(int j=1; j<5; j++)
            cout<<matrix[i][j]<<" ";
        cout<<endl;
    }
}

/**
input :
4 6
1 2 3
2 1 2
2 3 2
3 2 5
4 3 8
4 1 20
output :
0 3 5 100
2 0 2 100
7 5 0 100  //from 3 to 1 cost 7
15 13 8 0  //from 4 to 1 cost 15,4 to 2 cost 13
**/
