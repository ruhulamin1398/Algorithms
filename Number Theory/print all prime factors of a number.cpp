#include<bits/stdc++.h>
using namespace std;


void primefector( int n )
{
    while ( ! n/2 )
    {
        cout<<2<<" ";
        n/=2;
    }

    for( int i =3 ; i<sqrt(n) ; i+=2)
    {
    while ( ! n/i )
    {
    cout<<i<<" ";
    n/=i;
    }


    }




}



int main()
{
    int n ;
    cin>>n ;
//    primefector(n );



    return 0 ;
}
