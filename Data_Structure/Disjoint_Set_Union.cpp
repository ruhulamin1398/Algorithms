#include<bits/stdc++.h>
using namespace std;
int n,m, a,b, siz[100005], link[100005],circle;
int parent(int x)
{
    while(x != link[x])
        x = link[x];  /// parent update
    return x;
}
bool isSameLink(int a, int b)
{
    return parent(a) == parent(b); /// if same then return 1 else 0
}
int unite(int a, int b)
{
    a = parent(a),b = parent(b);
    if(a == b) /// if a and b is same set
    {
        circle++;
        return 0;
    }
    if(siz[a] < siz[b])
        swap(a,b);  /// allways small set add with big set
    siz[a] += siz[b]; /// size add
    link[b]=a; /// parent push
    return 1;
}
int main()
{
    int a,b,c,o;
    scanf("%d %d", &n, &m); ///n = node, m = graph input
    for(int i=1; i<=n; i++)
        siz[i] = 1, link[i] = i;
    while(m--)
    {
        scanf("%d %d",&a,&b);
        n -= unite(a,b);
    }
    printf("connected component : %d\n",n);
    for(int i=1; i<=n; i++)
        cout<<link[i]<<" "; ///dif link means dif component
    cout<<endl;
    scanf("%d",&o);
    while(o--)
    {
        scanf("%d", &a);
        if(a == 1) /// find parent of a node
        {
            scanf("%d", &b);
            cout << parent(b) << endl;
        }
        else if(a == 2) /// if two node are connected
        {
            scanf("%d %d", &b,&c);
            cout << isSameLink(b,c) << endl;
        }
        else  ///how many part of circle
            cout<<circle<<endl;
    }
}
/**
input :
8 6
1 2
1 3
4 5
5 6
6 7
2 5
5
1 8
1 2
2 2 4
2 8 1
3
output :
4 1 1 4 4 4 4 8
8
4
1
0
0
**/
