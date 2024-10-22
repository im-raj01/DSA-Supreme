#include <bits/stdc++.h> 
using namespace std;
// int f(int ind, vector<int>& heights){
//     //base case:
//     if(ind == 0){
//         return 0;
//     }

//     //do all stuffs on index:
//     int left = f(ind-1,heights) + abs(heights[ind]-heights[ind-1]);
//     int right = INT_MAX;
//     if(ind > 1)
//     right = f(ind-2,heights) + abs(heights[ind]-heights[ind-2]);


//     //return min of all stuffs:
//     return min(left,right);

// }

// mem:
// int f(int ind, vector<int>& heights,vector<int>&dp){
//     //base case:
//     if(ind == 0){
//         return 0;
//     }
//     if(dp[ind] != -1){
//         return dp[ind];
//     }
//     //do all stuffs on index:
//     int left = f(ind-1,heights,dp) + abs(heights[ind]-heights[ind-1]);
//     int right = INT_MAX;
//     if(ind > 1)
//     right = f(ind-2,heights,dp) + abs(heights[ind]-heights[ind-2]);


//     //return min of all stuffs:
//     return dp[ind]= min(left,right);

// }
// TAbulation:
// int f(int n, vector<int>& heights){
    
//     vector<int>dp(n,-1);
//     //base case dekh lo
//     dp[0] = 0;
//     //rec rel dekho
//     for(int i = 1;i<n;i++){
//         int left = dp[i-1] + abs(heights[i]-heights[i-1]);
//         int right = INT_MAX;
//         if(i > 1)
//         right = dp[i-2] + abs(heights[i]-heights[i-2]);
//         dp[i] = min(left,right);
//     }
//     return dp[n-1];

// }
int frogJump(int n, vector<int> &heights)
{
    // return f(n-1,heights);
    //step1: declare dp array:
    // vector<int>dp(n+1,-1);
    // f(n-1,heights,dp);
    // return dp[n-1];
    // return f(n,heights);

    //SPACE OPTIMISATION:   
    int prev1 = 0;
    int prev2 = 0;
    for(int i = 1;i<n;i++){
        int left = prev1 + abs(heights[i]-heights[i-1]);
        int right = INT_MAX;
        if(i > 1)
        right = prev2 + abs(heights[i]-heights[i-2]);
        int curri = min(left,right);
        prev2 = prev1;
        prev1 = curri;
    }
    return prev1;


}
int main(){
    
}