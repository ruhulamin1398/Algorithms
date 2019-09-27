#include<bits/stdc++.h>
using namespace std;
int num[10],use[10],k=0;
void per(int pos,int n)
{
    if(pos==n+1)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<num[j]<<" ";
        }
        cout<<endl;
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(use[i]==0)
        {
            use[i]=1;
            num[pos]=i;
            per(pos+1,n);
            use[i]=0;
        }
    }
}
int main()
{
    per(1,3);
    return 0;
}
/*
output :
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1

*/
