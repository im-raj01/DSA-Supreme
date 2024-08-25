#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    // priority_queue<int>pq; //max heap
    // pq.push(3);
    // pq.push(6);
    // pq.push(9);
    // pq.push(4);
    // pq.push(8);

    // cout<<"top element is "<<endl;
    // cout<<pq.top()<<endl;
    // pq.pop();
    // cout<<"top element is "<<endl;
    // cout<<pq.top()<<endl;
    
    //min-heap::
    priority_queue<int,vector<int>,greater<int>>pq; //max heap
    pq.push(3);
    pq.push(6);
    pq.push(9);
    pq.push(4);
    pq.push(8);

    cout<<"top element is "<<endl;
    cout<<pq.top()<<endl;
    pq.pop();
    cout<<"top element is "<<endl;
    cout<<pq.top()<<endl;


 return 0;
}