// https://leetcode.com/problems/house-robber/

#include<bits/stdc++.h>
using namespace std;
#define ll long long
// int solveUsingRec(vector<int>&nums,int idx){
    //base case:
//     if(idx >= nums.size()){
//         return 0;
//     }
//     // 1 case:
//     // exclude:
//     int exclude = solveUsingRec(nums,idx+1);
//     //include:
//     int include = solveUsingRec(nums,idx+2) + nums[idx];
    
//     return max(include,exclude);

// }

// int solveMem(vector<int>&nums,int idx,vector<int>&dp){
//     if(idx >= nums.size()){
//         return 0;
//     }
//     // 1 case:
//     if(dp[idx] != -1){
//         return dp[idx];
//     }
//     // exclude:
//     int exclude = solveUsingRec(nums,idx+1);
//     //include:
//     int include = solveUsingRec(nums,idx+2) + nums[idx];
    
//     dp[idx] = max(include,exclude);
//     return dp[idx];
// }




// n represents the index of current house:

int solveRec(vector<int>&nums,int n){
    if(n < 0){
        return 0;
    }
    if(n == 0){
        return nums[0];
    }

    int includeSum = solveRec(nums,n-2)+nums[n];
    int excludeSum = solveRec(nums,n-1)+0;
    return max(includeSum,excludeSum);
}

int solveMem(vector<int>&nums,int n,vector<int>&dp){
    if(n < 0){
        return 0;
    }
    if(n == 0){
        return nums[0];
    }

    // 
    if(dp[n] != -1){
        return dp[n];
    }

    int includeSum = solveMem(nums,n-2,dp)+nums[n];
    int excludeSum = solveMem(nums,n-1,dp)+0;
    dp[n] = max(includeSum,excludeSum);
    return dp[n];
}

// In the tabulation method be clear about what is representing dp[i] 
// here dp[i] represent kar raha h ith index tk maximum chori kitna ho sakta h

int solveTab(vector<int>&nums){
    int  n = nums.size();
    vector<int>dp(n,0);

    dp[0] = nums[0];

    for(int i = 1;i<=n;i++){
        int temp = 0;
        if(i-2 >= 0) 
            temp = dp[i-2];

        int include = temp + nums[i];
        int exclude = dp[i-1]+0;
        dp[i] = max(include,exclude);
    }

    // cout<<"print final dp array :"<<endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cout<<dp[i]<<" ";
    // }
    // cout<<endl;
    return dp[n];
}


int spaceOpt(vector<int>&nums){
    int  n = nums.size();
    int prev2 = 0;
    int prev1 = nums[0];
    int curr = 0;

    for(int i = 1;i<=n;i++){
        int temp = 0;
        if(i-2 >= 0) 
            temp = prev2;

        int include = temp + nums[i];
        int exclude = prev1+0;
        curr = max(include,exclude);

        prev2 = prev1;
        prev1 = curr;
    }

    return curr;
}

int rob(vector<int>& nums) {
        // int i = 0;
        // int sum = 0;
        // return solveUsingRec(nums,i);
        // int n = nums.size();
        // vector<int>dp(n+1,-1);
        // int i = 0;
        // return solveMem(nums,i,dp);


        int n = nums.size()-1;

        return solveTab(nums);
}
int main()
{
    vector<int>nums = {1,2,3,1};
    cout<<rob(nums)<<endl;


 return 0;
}