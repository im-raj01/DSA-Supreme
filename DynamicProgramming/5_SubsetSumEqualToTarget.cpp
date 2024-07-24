#include <bits/stdc++.h> 
// har possibility check karnih to
// right to left:
using namespace std;

bool solveUsingRec(int index,int target,vector<int>&arr){
    // base case:
    if (index == 0)
    {
        return (arr[index] == target);
    }
    if (target == 0)
    {
        return true;
    }

    // not take:
    bool NotTake = solveUsingRec(index-1,target,arr);
    //take:
    bool take = false;
    if(arr[index] <= target){
        take = solveUsingRec(index-1,target-arr[index],arr);
    }
    return (NotTake | take);
}

bool solveUsingMem(int index,int target,vector<int>&arr,vector<vector<int>>&dp){
    if (index == 0)
    {
        return (arr[0] == target);
    }
    if (target == 0)
    {
        return true;
    }
    if(dp[index][target] != -1){
        return dp[index][target];
    }

    // not take:
    bool NotTake = solveUsingMem(index-1,target,arr,dp);
    //take:
    bool take = false;
    if(arr[index] <= target){
        take = solveUsingMem(index-1,target-arr[index],arr,dp);
    }
    return dp[index][target]=(NotTake | take);
}

bool solveUsingTab(int n,int target,vector<int>&arr){
    vector<vector<bool>>dp(n,vector<bool>(target+1,0));
    dp[0][arr[0]] = 1;
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = 1;
    }
    for(int index = 1; index<n;index++){
        for(int tar = 0;tar<=target;tar++){
            // not take:
            bool NotTake = dp[index-1][tar];
            //take:
            bool take = false;
            if(arr[index] <= tar){
                take = dp[index-1][tar-arr[index]];
            }
            dp[index][tar]=(NotTake | take);
        }
    }
    return dp[n-1][target];
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    
    // return solveUsingRec(n-1,k,arr);
    // vector<vector<int>>dp(n,vector<int>(k+1,-1));
    // return solveUsingMem(n-1,k,arr,dp);
    return solveUsingTab(n,k,arr);
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int>arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    cout<<subsetSumToK(n,k,arr)<<endl;

    return 0;
}