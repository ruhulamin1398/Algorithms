#include<stdio.h>
int Point[10],Tree[40];
void Build(int node,int a,int b) ///complexity O(n)
{
    if(a==b) ///if same child
    {
        Tree[node]=Point[a];
        return ;
    }
    int Left=node*2;
    int Right=(node*2)+1;
    int Mid=(a+b)/2;
    Build(Left,a,Mid);
    Build(Right,Mid+1,b);
    Tree[node]=Tree[Left]*Tree[Right];
}
int Query(int node,int a,int b,int c,int d) ///complexity O(logn)
{
    if(a>d||b<c) ///out of query
        return 1;
    if(a>=c&&b<=d) ///inside and exact of query
        return Tree[node];
    int Left=node*2;
    int Right=(node*2)+1;
    int Mid=(a+b)/2;
    int m1=Query(Left,a,Mid,c,d);
    int m2=Query(Right,Mid+1,b,c,d);
    return m1*m2;
}
void Update(int node,int a,int b,int c,int n)///complexity O(logn)
{
    if(a>c||b<c) ///out of update pos
        return ;
    if(a==c&&b==c) ///exact pos of c
    {
        Tree[node]=n;
        return;
    }
    int Left=node*2;
    int Right=(node*2)+1;
    int Mid=(a+b)/2;
    Update(Left,a,Mid,c,n);
    Update(Right,Mid+1,b,c,n);
    Tree[node]=Tree[Left]*Tree[Right];
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
        scanf("%d",&Point[i]);
    Build(1,1,n);
    printf("%d\n",Query(1,1,n,2,4)); ///multiple of 2 to 4 pos : 105
    Update(1,1,n,3,0); ///pos 3 update by 0
    printf("%d",Query(1,1,n,2,4)); ///now multiple of 2 to 4 pos : 0
}
/**
input :
5
1 3 5 7 9
output :
105
0
**/
