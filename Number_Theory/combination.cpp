#include<bits/stdc++.h>
using namespace std;
int number[20];
int n,k;
void com(int at,int last)
{
    if(at==k+1)
    {
        for(int i=1;i<=k;i++)
        {
            cout<<number[i]<<" ";
        }
        cout<<endl;
        return ;
    }
    for(int i=last+1;i<=n-k+at;i++) //loop break after turning k time
    {
        number[at]=i;
        com(at+1,i);
    }
}
int main()
{
    cin>>n>>k; //take k element from n element combination/
    com(1,0);
    return 0;
}

/*
input :
3 2
output :
1 2
1 3
2 3
*/
