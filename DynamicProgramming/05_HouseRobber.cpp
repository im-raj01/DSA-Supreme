#include<bits/stdc++.h>
using namespace std;
#define ll long long

int f(int ind, vector<int>& nums,vector<int>&dp) {
    // base case:
    if(ind < 0){
        return 0;
    }
    if(dp[ind]!=-1){
        return dp[ind];
    }
    //har index all stuffs perform karo:
    //take call:
    int Take = f(ind-2,nums,dp) + nums[ind];
    int NotTake = f(ind-1,nums,dp);
    //return max of all stuffs:
    return dp[ind] = max(Take, NotTake);

}
//TAbulation:
int SolveUsingTab(int n,vector<int>&nums){
    //step 1;
    vector<int>dp(n,-1);
    //step 2: base case:
    dp[0] = nums[0];
    dp[1] = nums[1];
    for (int ind = 1; ind < n; ind++)
    {
        int Take = nums[ind];
        if(ind > 1)
        Take = dp[ind-2] + nums[ind];
        int NotTake = dp[ind-1];
        dp[ind] = max(Take, NotTake);
        
    }
    return dp[n-1];
    
}

int main()
{
    vector<int>nums={2,7,9,3,1};
    int n = nums.size();
    // vector<int>dp(n+1,-1);


    // cout<<f(n-1,nums,dp);
    // cout<<SolveUsingTab(n,nums);
    int prev1 = nums[0];
    int prev2 = 0;
    for(int ind = 1;ind<n;ind++){
        int Take = nums[ind];
        if(ind > 1)
        Take = prev2 + nums[ind];
        int NotTake = prev1;

        int curri = max(Take, NotTake);
        prev2 = prev1;
        prev1 = curri;
    }
    cout<<prev1;
 return 0;
}