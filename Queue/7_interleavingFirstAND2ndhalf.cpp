#include<bits/stdc++.h>
using namespace std;
#define ll long long


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
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    // q.push(8);
    interLeaveQueue(q);

    
    while (!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }

 return 0;
}