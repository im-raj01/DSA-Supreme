#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void reverseQueue(queue<int>&q){
    stack<int>st;
    while (!q.empty())
    {
        st.push(q.front());
        q.pop();
    }
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
}

void reverseUsingRec(queue<int>&q){
    //base case:
    if(q.empty()){
        return;
    }
    //for this curr element 
    //A - front store kar lo
    int front = q.front();
    //B-
    q.pop();
    //C - rec call
    reverseUsingRec(q);
    //D - BT karte waqt:
    q.push(front);
}
int main(){
    queue<int>q;
    q.push(3);
    q.push(6);
    q.push(9);
    q.push(2);
    q.push(8);
    
    reverseUsingRec(q);
    while (!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    cout<<endl;
    

}