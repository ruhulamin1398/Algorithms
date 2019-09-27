#include<bits/stdc++.h>
using namespace std;
int main()
{
    char c;
    map<char,int>m;
    for(int i=1; i<=10; i++)
    {
        cin>>c;
        m[c]++;  /// frequency count - [n*log(n)]
    }
    for (auto& x: m)
        cout << x.first << ": " << x.second << '\n';

    m.clear(); ///clear a map - [O(n)]

    for(int i=1; i<=10; i++)
    {
        cin>>c;
        m[c]=i;  /// c index = i of map
    }
    for (auto& x: m)
        cout << x.first << ": " << x.second << '\n';

    for(int i=97; i<=100; i++) ///access with loop
        cout<<(char)i<<" "<<m[i]<<endl;

    map<char,int>n;
    n=m;  ///assign value m to n - [O(size of m)]
    m.clear();
    cout<<"after assign the elements of n :"<<endl;
    for(auto& x: n)
        cout << x.first << ": " << x.second << '\n';

    cout<<"m assign to n map,so reverse the map : n "<<endl;
    map<char,int>::reverse_iterator rit;
    for(rit=n.rbegin(); rit!=n.rend(); rit++) /// map reverse
        cout<<rit->first<<" "<<rit->second<<endl;

    m['a']=20,m['b']=40,m['c']=60,m['d']=80,m['e']=100;
    map<char,int>::iterator itlow,itup,it;
    itlow=m.lower_bound ('b');  /// itlow points of pointer to b  - [logn]
    itup=m.upper_bound ('d');   /// itup points of pointer to e (not d!) - [logn]
    cout<<"for lower bound : "<<itlow->first<< " "<<itlow->second <<endl;
    cout<<"for upper bound : "<<itup->first<< " "<<itup->second <<endl;

    m.erase(itlow,itup); /// erases [itlow,itup)  - [O(itup pos - itlow pos)]
    itlow=m.find('a');
    m.erase (itlow);  ///erases form position - [O(1)]
    m.erase ('e');  ///erases form value - [log(n)]
    cout<<"Now the size of m : "<<m.size()<<endl; /// map size  - [O(1)]

    m.swap(n);   ///map swap m to n - [O(1)]
    cout<<"now the size of n : "<<n.size()<<endl;
    cout<<"now the size of m : "<<m.size()<<endl;
}
/**
input :
a b b a c c d a c a
a b b a c c d a c a

output :
a 4
b 2
c 3
d 1
b 3
c 9
d 7
a 10
b 3
c 9
d 7
after assign the elements of n :
a: 10
b: 3
c: 9
d: 7
m assign to n map,so reverse the map : n
d 7
c 9
b 3
a 10
for lower bound : b 40
for upper bound : e 100
Now the size of m : 0
now the size of n : 0
now the size of m : 4

**/
