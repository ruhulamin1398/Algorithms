#include<bits/stdc++.h>
using namespace std;
int value[]= {120,400,280,150,200},weight[]= {1,7,4,3,4},cap=10,N=5;
int DP[12][6];
int knapSack(int w,int n)
{
    int gain1,gain2;
    if(w==cap||n==N)
        return 0;
    if(DP[w][n]!=-1)
        return DP[w][n];
    if(w+weight[n]<=cap)
        gain1=value[n]+knapSack(w+weight[n],n+1);
    else
        gain1=0;
    gain2=knapSack(w,n+1);
    return DP[w][n]=max(gain1,gain2);
}
int main()
{
    memset(DP,-1,sizeof(DP));
    cout<<knapSack(0,0);
}
/**
output : 600
**/
