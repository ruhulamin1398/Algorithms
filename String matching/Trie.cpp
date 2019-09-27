#include<bits/stdc++.h>
#define LIM 100005
using namespace std;
int trie[LIM][30],id=0; /// trie[u][c] : u theke c char diye kon node e jay
void add(string word) ///create link
{
    int cur = 0;
    for(int i=0; i<word.size(); i++)
    {
        int d = word[i] - 'a';
        if(trie[cur][d] == 0)
            trie[cur][d] = ++id;
        cur = trie[cur][d];
    }
}
int query(string word)
{
    int cur = 0;
    for(int i=0; i<word.size(); i++)
    {
        int d = word[i] - 'a';
        if(trie[cur][d] == 0)
            return 0;
        cur = trie[cur][d];
    }
    return 1;
}
int main()
{
    int T,n,Q;
    scanf("%d", &T);
    for(int t=1; t<=T; t++)
    {
        id = 0;
        string word;
        scanf("%d", &n);
        for(int i=0; i<n; i++)
        {
            cin >> word;
            add(word);
        }
        scanf("%d", &Q);
        while(Q--)
        {
            cin >> word;
            cout << query(word) << endl;
        }
    }
}

/**
input :
1
3
sam
tagor
mithi
2
sagor
mi

output :
0
1
**/
