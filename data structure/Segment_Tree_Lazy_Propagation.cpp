#include<stdio.h>
int Point[10];
struct info
{
    int prop, sum;
} Tree[40]; ///update value we store in prop
void Build(int node,int a,int b) ///complexity O(n)
{
    if(a==b) ///if same child
    {
        Tree[node].sum=Point[a];
        return ;
    }
    int Left=node*2;
    int Right=(node*2)+1;
    int Mid=(a+b)/2;
    Build(Left,a,Mid);
    Build(Right,Mid+1,b);
    Tree[node].sum=Tree[Left].sum+Tree[Right].sum;
}
void Update(int node,int a,int b,int i,int j,int p) ///O(logn)
{
    if (i > b || j < a)
        return;
    if (a >= i && b <= j)
    {
        Tree[node].sum+=((b-a+1)*p); ///b-a+1=how many leaf connect
        Tree[node].prop+=p; ///store propagation value
        return;
    }
    int Left = node * 2;
    int Right = (node * 2) + 1;
    int Mid = (b + a) / 2;
    Update(Left, a, Mid, i, j, p);
    Update(Right, Mid + 1, b, i, j, p);
    Tree[node].sum =Tree[Left].sum+Tree[Right].sum+(b-a+1)*Tree[node].prop;
}
int Query(int node,int a,int b,int i,int j,int carry=0)///O(logn)
{
    if (i > b || j < a)
        return 0;
    if (a >= i and b<= j)
        return Tree[node].sum + carry * (b - a + 1); ///carry all*response leaf
    int Left = node << 1;
    int Right = (node << 1) + 1;
    int Mid = (b + a) >> 1;
    int p1 = Query(Left, a, Mid, i, j, carry + Tree[node].prop); ///add carry value
    int p2 = Query(Right, Mid + 1, b, i, j, carry + Tree[node].prop);
    return p1 + p2;
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&Point[i]);
    Build(1,1,n); ///Create Tree
    printf("%d\n",Query(1,1,n,1,n)); ///sum value
    Update(1,1,n,1,n,2); ///add 2 to pos 1 to 5
    printf("%d\n",Query(1,1,n,1,n)); ///sum value after update
    Update(1,1,n,1,3,3); ///add 2 to pos 1 to 3
    printf("%d\n",Query(1,1,n,1,n)); ///sum value after update
    printf("%d",Query(1,1,n,1,1)); ///sum value after update
    return 0;
}
/**
input :
5
1 3 5 7 9
output :
25
35
44
6
**/

