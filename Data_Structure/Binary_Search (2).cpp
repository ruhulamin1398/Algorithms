#include<bits/stdc++.h>
using namespace std;
int main()
{
    int M[]= {0,2,4,9},low,high,x;
    cin>>x;
    low=0,high=4;
    while(low<high)
    {
        int mid=(low+high)/2;
        if(M[mid]<x)
            low=mid+1;
        else
            high=mid;
    }
    cout<<"For lower_bound : "<<low<<endl;
    low=0,high=4;
    while(low<high)
    {
        int mid=(low+high)/2;
        if(M[mid]<=x)
            low=mid+1;
        else
            high=mid;
    }
    cout<<"For upper_bound : "<<low<<endl;
    return 0;
}
/**
input :
7
output :
For lower_bound : 3 Equal/exact greater
For upper_bound : 5 Must greater
**/
