#include<bits/stdc++.h>
using namespace std;
int main()
{
    string mystring,nystring;
    cin>>mystring; ///can't get after " " [O(length)]
    cout<<"mysting : "<<mystring; /// [O(length)]
    getchar();
    mystring.clear(); ///clear string - [O(1)]
    cout<<endl;
    getline(cin,mystring);  ///get all char - [O(length)]
    cout<<endl<<"mysting(using getline) : "<<mystring;

    cout<<endl<<"mystring size : "<<mystring.size(); ///size - [O(1)]

    nystring.assign(mystring);
    cout << endl<<"after assign mystring to nystrig : "<<nystring;
    nystring.assign(mystring,10,9);
    ///a.assign(b,10,9); assign a to b of 10 index to 18
    ///a.assign(b,9); assign a to b of first 9 char
    ///a.assign(10,'*'); assign a to 10 *
    ///a.assign(b.begin()+16,b.end()-12); assign b of index 16 to back of end of -12
    cout << endl<<"after assign nystrig : "<<nystring;

    reverse(nystring.begin(), nystring.end());  /// [O(length)]
    cout<<endl<<"after reverse nystring : "<<nystring;

    cout<<endl<<"print mystring reverse way";
    for (auto x = mystring.rbegin(); x != mystring.rend(); ++x) /// [O(length)]
        cout << ' ' << *x;

    mystring+=nystring; /// [O(length)]
    cout<<endl<<"after adding mystring : "<<mystring;

    if(mystring==nystring)  ///  [O(length)],also can use(<,>,=<,=>,!=)
        cout<<endl<<"my and ny are same";
    else
        cout<<endl<<"my and ny are not same";

    mystring=nystring; ///assign with operator [O(length)]
    cout<<endl<<"mystring : "<<mystring<< " & nystring : " <<nystring;

    mystring.swap(nystring);  ///swaping - [O(1)]
    cout<<endl<<"after swaping : ";
    cout<<endl<<"mystring : "<<mystring<< " & nystring : " <<nystring;

    mystring.clear();
    if(mystring.empty())  /// [O(1)]
        cout<<endl<<"mystring is empty now..";
    else
        cout<<endl<<"mystring is not empty now";

    mystring.assign("This is an example sentence.");
    mystring.erase (10,8); ///erash index 10 to 17
    mystring.erase (mystring.begin()+9); ///erash 9th index
    mystring.erase (7); ///erash all after 6 index
    cout<<endl<<"after erashing mystring : "<<mystring;

    string newstring="We think in generalities, but we live in details.";
    string newstring2 = newstring.substr (3,5); ///creat substring with 5 char after 2th index

    int pos = newstring.find("live"); ///[O(length)]
    ///if "live" a stay in sting than return l index else -1

    string newstring3 = newstring.substr (pos); /// get from "live" to the end - [O(substr.length)]
    cout << "new stirng2 : "<<newstring2 << endl<<"new stirng3 : " << newstring3;

}
/**
input:
ABCDEFGHIJKLMNOPQRSTUVWXYZ
abcde fghij klmnop qrstu vwxyz

output:
mysting : ABCDEFGHIJKLMNOPQRSTUVWXYZ
mysting(using getline) : abcde fghij klmnop qrstu vwxyz
mystring size : 30
after assign mystring to nystrig : abcde fghij klmnop qrstu vwxyz
after assign nystrig : j klmnop
after reverse nystring :  ponmlk j
print mystring reverse way z y x w v   u t s r q   p o n m l k   j i h g f   e d c b a
after adding mystring : abcde fghij klmnop qrstu vwxyz ponmlk j
my and ny are not same
mystring :  ponmlk j & nystring :  ponmlk j
after swaping :
mystring :  ponmlk j & nystring :  ponmlk j
mystring is empty now..
after erashing mystring : This isnew stirng2 : think
new stirng3 : live in details.
**/
