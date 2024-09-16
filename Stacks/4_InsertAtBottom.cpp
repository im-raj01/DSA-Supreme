#include<bits/stdc++.h>
using namespace std;
#define ll long long

void insertAtBottom(stack<int>&st, int target){
    // base case: 
    if(st.empty()){
        cout<<"stack is empty"<<endl;
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
void printStack(stack<int>st){
    cout<<"Printint Stack"<<endl;
    while (!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }
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

    int target = st.top();
    st.pop();
    insertAtBottom(st,target);
    cout<<endl;
    cout<<"print after insert at bottom "<<endl;
    printStack(st);

 return 0;
}