#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
    queue<int>q;

    // insertion:
    q.push(5);
    q.push(15);
    q.push(25);
    q.push(35);

    //size:
    cout<<"size of queue is "<<q.size()<<endl;
    //pop
    q.pop();
    cout<<"size of queue is "<<q.size()<<endl;

    //front:
    cout<<"front is "<<q.front()<<endl;
    //empty check
    if(q.empty()){
        cout<<"q is empty"<<endl;
    }
    else{
        cout<<"q is not empty"<<endl;

    }

 return 0;
}