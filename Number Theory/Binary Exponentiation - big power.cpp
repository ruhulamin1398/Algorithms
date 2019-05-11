/// Complixity 0(logn)




#include<bits/stdc++.h>
using namespace std;

long long binpow( long long  base, long long  pow )
{

    if (   pow==0 )
        return 1;

    long long result= binpow( base, pow/2);
    if( pow&1)
        return result*result*base;
    else
        return result *result;

}

int main()
{
    cout<<binpow( 3, 13);
    return 0 ;
}




