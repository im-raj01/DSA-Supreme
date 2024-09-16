#include<bits/stdc++.h>
using namespace std;
#define ll long long

int getMiddle(stack<int>&st, int size){
    // #1 --> put all elements in a vector and find middle : tc: O(n)+O(n) && s.c:O(n) for vector space;
    // #2 -> use recursion to push and pop in the same stack without using external stack or vector:
    if(st.size() == (size/2)+1){
        return st.top();
    }

    // for the current element:
    //A -- store top element
    int topElement = st.top();
    //B- pop the top one
    st.pop();
    // Step C - Recursive call to get the middle element
    int middleElement = getMiddle(st,size);
    //D - backtrack karte waqt topele push kar do
    st.push(topElement);
    return middleElement;

}
int main()
{
    stack<int>st;
    //push elements into the stack
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    st.push(70);
    int size = st.size();

    cout<<"Middle Element of Stack is "<<getMiddle(st,size)<<endl;

 return 0;
}