#include<bits/stdc++.h>
using namespace std;
long long coin[51],limit[51],n,make,dp[51][1002];
long long cn(long long i,long long amount)
{
    if(amount==0)
        return 1;
    if(i>=n)
    {
        if(amount==0)
            return 1;
        else
            return 0;
    }
    if(dp[i][amount]!=-1)
        return dp[i][amount];
    long long r=0;
    for(long long j=0; (j<=limit[i]) && (j*coin[i]<=amount); j++)
    {
        r=r+cn(i+1,amount-coin[i]*j);
    }
    return dp[i][amount]=r;
}

int main()
{
        memset(dp,-1,sizeof dp);
        cin>>n>>make;
        for(long long i=0; i<n; i++)
        {
            long long a;
            cin>>a;
            coin[i]=a;
        }
        for(long long i=0; i<n; i++)
        {
            long long a;
            cin>>a;
            limit[i]=a;
        }
        cout<<cn(0,make);
    return 0;
}

/**
input :
3 4
1 2 3 2 2 1
output :
3
**/

