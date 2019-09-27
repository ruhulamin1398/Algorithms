#include<bits/stdc++.h>
using namespace std;
int dp[20];
int F( int n )
{
    if( n == 0 )
        return 0;
    if( n == 1 )
        return 1;
    if( dp[n]!=-1 )
        return dp[n]; //directly return value
    else
    {
        dp[n] = F( n-1 ) + F( n-2 ); //memorize value
        return dp[n];
    }
}
int main()
{
    int n;
    for(int i=0; i<20; i++)
        dp[i]=-1;
    cin>>n;
    cout<<F(n);
}
/*
input :
10
output :
55
*/
