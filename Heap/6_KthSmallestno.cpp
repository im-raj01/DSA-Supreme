#include<bits/stdc++.h>
using namespace std;
#define ll long long

// very very Important::

int getKthGreatest(int arr[],int n , int k ){
    //create min heap
    priority_queue<int,vector<int>,greater<int>>pq;
    //insert initial k elements:
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }
     // for rem elements, push only if element is greater than pq.top():
    for (int i = k; i < n; i++)
    {
        int element = arr[i];
        if(element > pq.top()){
            pq.pop();
            pq.push(element);
        }
    }
    return pq.top();
    
}
int getKthSmallest(int arr[],int n , int k ){
    //create max heap
    priority_queue<int>pq;
    //insert initial k elements:
    for (int i = 0; i < k; i++)
    {
        pq.push(arr[i]);
    }

    // for rem elements, push only if element is smaller than pq.top():
    for (int i = k; i < n; i++)
    {
        int element = arr[i];
        if(element < pq.top()){
            pq.pop();
            pq.push(element);
        }
    }
    return pq.top();
    
}
int main()
{
    int arr[] = {10,5,20,4,15};
    int n = 5;
    int k = 3;
    int kthSmallestno = getKthSmallest(arr,n,k);
    int kthGreatestno = getKthGreatest(arr,n,k);
    cout<<"kthSmallestno is "<<kthSmallestno<<endl;
    cout<<"kthGreatestno is "<<kthGreatestno<<endl;
    
 return 0;
}