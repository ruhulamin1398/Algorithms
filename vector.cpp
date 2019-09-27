#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> myvector (10),nyvector(10);   /// 10 zero-initialized ints & size 10
    for (int i=0; i<myvector.size(); i++)  /// size of vector - [O(1)]
        myvector.at(i)=i; /// access position - [O(1)]

    cout<<"myvector print reverse : ";
    for (auto rit = myvector.rbegin(); rit != myvector.rend(); ++rit)
        cout << ' ' << *rit;
    for (int i=10; i<=17; i++)
        myvector.push_back(i);
    cout<<endl<<"myvector : ";
    for(int i=0; i<myvector.size(); i++)
        cout<<myvector[i]<<" ";

    cout<<endl<<"after reverse myvector 5 to 10 position: ";
    reverse(myvector.begin() + 5, myvector.begin() + 11);  ///reverse - [O(n)]
    for(int i=0; i<myvector.size(); i++)
        cout<<myvector[i]<<" ";

    cout<<endl<<"after reverse myvector : ";
    reverse(myvector.begin(), myvector.end());
    for(int i=0; i<myvector.size(); i++)
        cout<<myvector[i]<<" ";

    myvector.erase (myvector.begin()+5);/// erase the 6th element -[O(ele num+n)]
    myvector.erase (myvector.begin(),myvector.begin()+3);/// erase the first 3 elements
    cout<<endl<<"after erasing my vector : ";
    for(int i=0; i<myvector.size(); i++)
        cout<<myvector[i]<<" ";

    cout<<endl<<"ny vector : ";
    for(int i=1; i<5; i++)
        nyvector[i]=i*5;
    for(int i=0; i<nyvector.size(); i++)
        cout<<nyvector[i]<<" ";

    nyvector.swap(myvector); ///swap my to ny [O(1)]
    cout<<endl<<"after swaping nyvetor : ";
    for(int i=0; i<nyvector.size(); i++)
        cout<<nyvector[i]<<" ";
    cout<<endl<<"after swaping myvetor : ";
    for(int i=0; i<myvector.size(); i++)
        cout<<myvector[i]<<" ";

    myvector=nyvector;  ///assign ny to my [O(size)]
    cout<<endl<<"after assign nyvetor : ";
    for(int i=0; i<nyvector.size(); i++)
        cout<<nyvector[i]<<" ";
    cout<<endl<<"after assign myvetor : ";
    for(int i=0; i<myvector.size(); i++)
        cout<<myvector[i]<<" ";

    myvector.clear();
    cout<<endl<<"after clear myvetor size : "<<myvector.size();
    vector<int>v[10]; ///2D of adjacent vector
    for(int i=0; i<10; i++)
        v[i].clear(); ///clear adjecent
}
/**
input:
NULL

output:
myvector print reverse :  9 8 7 6 5 4 3 2 1 0
myvector : 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17
after reverse myvector 5 to 10 position: 0 1 2 3 4 10 9 8 7 6 5 11 12 13 14 15 16 17
after reverse myvector : 17 16 15 14 13 12 11 5 6 7 8 9 10 4 3 2 1 0
after erasing my vector : 14 13 11 5 6 7 8 9 10 4 3 2 1 0
ny vector : 0 5 10 15 20 0 0 0 0 0
after swaping nyvetor : 14 13 11 5 6 7 8 9 10 4 3 2 1 0
after swaping myvetor : 0 5 10 15 20 0 0 0 0 0
after assign nyvetor : 14 13 11 5 6 7 8 9 10 4 3 2 1 0
after assign myvetor : 14 13 11 5 6 7 8 9 10 4 3 2 1 0
after clear myvetor size : 0

**/
