#include<bits/stdc++.h>
using namespace std;
#define ll long long

void InsertSorted(stack<int>&s,int target){
    // base case:
    //empty base case is written first;
    if(s.empty() || s.top() >= target){
        s.push(target);
        return;
    }
    // current element ke liye:
    // A -- store top elemtnt
    int topElement = s.top();
    //b
    s.pop();
    // rec call
    InsertSorted(s,target);
    //BT:
    s.push(topElement);
}

void sortAStack(stack<int>&s){
    //base case:
    if(s.empty()){
        return;
    }
    // for current element:
    int topElement = s.top();
    s.pop();
    sortAStack(s);
    InsertSorted(s,topElement);

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
//   vector<int>v;
  st.push(7);
  st.push(11);
  st.push(3);
  st.push(5);
  st.push(9);

  sortAStack(st);
  printStack(st);


 return 0;
}