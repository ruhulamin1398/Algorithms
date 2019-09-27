
/// runnig time for big number  0.1 Sec

#include<bits/stdc++.h>
using namespace std;

long long gcd(long long  a, long long  b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
long long nCr(long long  n, long long  r)
{
	long long p = 1, k = 1;
	if (n - r < r)
		r = n - r;

	if (r != 0) {
		while (r) {
			p *= n;
			k *= r;
			//long long m = __gcd(p, k);
			long long m =gcd(p, k);
			p /= m;
			k /= m;
			n--;
			r--;
		}
	}

	else
		p = 1;
	return p;
}


int main()
{	cout<< nCr(10000000, 500000)<<endl;
    return 0;
}
