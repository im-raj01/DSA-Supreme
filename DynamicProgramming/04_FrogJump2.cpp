#include<bits/stdc++.h>
using namespace std;
#define ll long long
//rec sol:
int f(int ind, int k, vector<int>&heights,vector<int>&dp){
    //base case:
    if(ind == 0){
        return 0;
    }
    if(dp[ind] != -1){
        return dp[ind];
    }
    int mini = INT_MAX;

    //do all stuffs on this index:
    for(int j = ind-1; j>= ind-k && j>=0;j--){
        int jump = f(j,k,heights,dp) + abs(heights[ind]-heights[j]);
        mini = min(jump,mini);
    }   
    return dp[ind] = mini;
}
int main()
{

    int n,k;cin>>n>>k;
    vector<int>heights(n);
    for (int i = 0; i < n; i++)
    {
        int h;cin>>h;
        heights[i] = h;
    }
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<heights[i]<<" ";
    // }
    vector<int>dp(n+1,-1);
    
    cout<< f(n-1,k,heights,dp);
 return 0;
}