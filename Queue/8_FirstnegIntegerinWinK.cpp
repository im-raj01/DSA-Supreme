#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve(int arr[],int n, int k){
    deque<int>q;
    //first k elements:
    for (int i = 0; i < k; i++)
    {
        if(arr[i] < 0){
            q.push_back(i);
        }
    }
    vector<int>ans;
    //rem window ko process karo:
    for (int i = k; i < n; i++)
    {
        //purani win ka ans likh lo:
        if(q.empty()){
            ans.push_back(0);
        }
        else{
            ans.push_back(arr[q.front()]);
        }

        //out of win ele ko remove kar do dq se:
        while (!q.empty() && q.front() <= i-k)
        {
            q.pop_front();
        }

        //insertion wala 
        if(arr[i] < 0){
            q.push_back(i);
        }
        
    }
    //for the last window
    if(q.empty()){
            ans.push_back(0);
        }
        else{
            ans.push_back(arr[q.front()]);
        }

    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
    
    

}

int main()
{
    int arr[] = {12,-1,-7,8,-15,30,16,28};
    int size = 8;

    int k = 3;

    solve(arr,size,k);
 return 0;
}