/*
The smallest number in every segment

log n

output  :
10 3 3 3 2 2 2 44 55 22 11 11 11 5
*/


#include<bits/stdc++.h>
using namespace std;
int main() {
    int arr[]={10,12,21,3,44,7,2,44,55,66,44,22,11,41,25,5};

    int len= sizeof(arr)/sizeof(arr[0]);
    int segment=3;
    vector<int> result;
    vector<int > :: iterator it;
    deque<int > d;
    d.push_back(arr[0]);

    for( int i =1 ; i<len ; i++){
            while (d.size() !=0 && d.back()>arr[i])
                d.pop_back();
            d.push_back(arr[i]);
            if(i<(segment-1))
                continue;
            result.push_back(d.front());
            if(d.front()==arr[i-segment+1])
                d.pop_front();
    }
    for( it= result.begin() ; it!=result.end() ; it++)
        cout<<*it<<" ";
    return 0 ;
}
