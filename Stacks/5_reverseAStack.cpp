#include<bits/stdc++.h>
using namespace std;
#define ll long long

void printStack(stack<int>st){
    cout<<"Printint Stack"<<endl;
    while (!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
}

void insertAtBottom(stack<int>&st, int target){
    // base case: 
    if(st.empty()){
        // cout<<"stack is empty"<<endl;
        st.push(target);
        return;
    }
    // for the current element :
    int topElement = st.top();
    st.pop();
    // C - recursive call:
    insertAtBottom(st,target);
    // backtrack:
    st.push(topElement);

}

void reverseStack(stack<int>&st){
    //base case:
    if(st.empty()){
        return;
    }

    // for the current element :
    //A
    int topElement = st.top();
    //B
    st.pop();
    //C --> we want to insert the topElement at bottom of reverse stack without current element :
    reverseStack(st);
    //
    insertAtBottom(st,topElement);

}
int main()
{
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    st.push(70);
    printStack(st);
    reverseStack(st);
    cout<<endl;
    cout<<"Print after reversing the stack"<<endl;

    printStack(st);

 return 0;
}