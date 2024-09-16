#include<iostream>
#include<deque>
using namespace std;

int main(){
    deque<int>dq;

    dq.push_front(5);
    dq.push_front(10);
    dq.push_front(50);

    dq.push_back(20);
    dq.push_back(30);
    cout<<"Front : "<<dq.front()<<endl;
    cout<<"At back "<<dq.back()<<endl;
    cout<<"size is :"<<dq.size()<<endl;
    dq.pop_front();
    cout<<"size is :"<<dq.size()<<endl;
    dq.pop_back();
    cout<<"size is :"<<dq.size()<<endl;

    cout<<"Front : "<<dq.front()<<endl;
}