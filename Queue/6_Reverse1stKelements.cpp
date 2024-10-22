#include<bits/stdc++.h>
using namespace std;
#define ll long long

void reverseK(queue<int>&q, int k){
    //step a; queue k elements ko stack me dalo
    int size = q.size();

    if(k == 0 || k>size){
        return;
    }
    stack<int>st;
    int cnt =0;
    while (!q.empty() && cnt < k)
    {
        int temp = q.front();
        q.pop();
        st.push(temp);
        cnt++;
    }
    //b - stack se q me wapas 
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
    //c - push n-k elements from front to back in same order:
    int rem = size-k;
    cnt = 0;
    while (cnt < rem)
    {
        int temp = q.front();
        q.pop();
        q.push(temp);
        cnt++;
    }
    
}

void interLeaveQueue(queue<int>&q){
    //step A:
    int n = q.size();
    if(n == 0)return;
    int k = n/2;
    int cnt = 0;
    queue<int>q2;
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        q2.push(temp);
        cnt++;
        if(cnt == k){
            break;
        }
    }
    
    // B -> interleaving start kardo:
    while (!q.empty() && !q2.empty())
    {
        int first = q2.front();
        q2.pop();

        q.push(first);
        int second = q.front();
        q.pop();
        q.push(second);

    }
    if(n&1){
        int element = q.front();
        q.pop();
        q.push(element);
    }

}
int main()
{
    queue<int>q;
    q.push(3);
    q.push(6);
    q.push(9);
    q.push(12);
    q.push(15);
    reverseK(q,0);
    while (!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }

 return 0;
}