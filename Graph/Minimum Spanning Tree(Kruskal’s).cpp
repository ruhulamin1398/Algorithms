#include<bits/stdc++.h>
using namespace std;
int parent[200005];
struct  node
{
    int u;
    int  v;
    int cost;

} arr[200005];
bool cmp(node a, node b)
{
    return a.cost<b.cost;
}
int findParent(int x )
{
    if(x==parent[x])
        return x ;
    else
        return parent[x]=findParent(parent[x]);
}

int main()
{
    int n,e;


        cin>>n>>e;

        int cnt=0,totalCost=0,pathCost=0;
        for(int i =0 ; i<n ; i++)
        {
            parent[i]=i;
        }
        for( int i =0 ; i<e ; i++)
        {
            cin>>arr[i].u>>arr[i].v>>arr[i].cost;
            totalCost+=arr[i].cost;
        }

        sort(arr,arr+e,cmp);

        for( int i=0 ; i<e ; i++)
        {
            int a, b ;
            a= findParent(arr[i].u);
            b= findParent(arr[i].v);
            if(a!=b )
            {
               parent[a]=b;
                cnt++;
                pathCost += arr[i].cost;
            }
            if(cnt==n-1)
            {
                break;
            }

        }
        cout<<totalCost-pathCost<<endl;




    return 0 ;

}



