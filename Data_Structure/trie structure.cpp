#include<bits/stdc++.h>
using namespace std;

struct node
{
    bool found;
     node * next[30];
    node()
    {
         found = false;
        for( int i =0 ; i< 26 ; i++)
        {

            next[i]= NULL;

        }
    }

}*root;

void newWord(string s )
{
    node* current = root;

    for( int i = 0 ; i< s.size() ; i++)
    {

        int id = s[i]-'a';
        if( current->next[id]==NULL )
            current->next[id]= new node();
        current = current->next[id];
    }
    current->found = true;
}

bool wordSearch( string s )
{
    node *current = root ;

    for(int i =0 ; i< s.size() ; i++)
    {
        int id = s[i]-'a';
        if(current ->next[id]==NULL)
            return  false ;
        current = current->next[id];
    }
    return current->found;



}

int main()
{
   root = new node();
    int n ;
    string s ;

    cin>>n ;
    while ( n--)
    {
        cin>>s;
        newWord(s);
    }
    cin>>n ;
    while( n--)
    {
        cin>>s;
        cout<<wordSearch(s);
    }



    return 0 ;
}
