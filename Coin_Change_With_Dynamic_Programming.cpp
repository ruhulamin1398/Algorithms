#include<bits/stdc++.h>
using namespace std;
int coin[]= {1,2,3},make,dp[6][100]; //value of coins available
int call(int i,int amount)
{
    if(i>=3) //all coin has taken
    {
        if(amount==make)
            return 1;
        else
            return 0;
    }
    if(dp[i][amount]!=-1)
        return dp[i][amount]; //no need to calculate same state twice
    int ret1=0,ret2=0;
    if(amount+coin[i]<=make)
        ret1=call(i,amount+coin[i]);
    ret2=call(i+1,amount);
    return dp[i][amount]=ret1+ret2; //storing and returning.
}
int main()
{
    while(cin>>make) //make is target value
    {
        memset(dp,-1,sizeof(dp));
        cout<<call(0,0)<<endl;
    }
    return 0;
}
/*
input :
3
10
output:
3
14
*/
