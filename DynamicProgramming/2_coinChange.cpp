// https://leetcode.com/problems/coin-change/description/

#include<bits/stdc++.h>
using namespace std;
#define ll long long


    int solveUsingRec(vector<int>& coins, int amount){
        // base case:
        // cout<<"call for amount "<<amount<<endl;
        if(amount  == 0){
            return 0;
        }
        if(amount < 0){
            return INT_MAX;
        }

        int mini = INT_MAX;
        // 1 case:
        for(int i = 0;i<coins.size(); i++){
            int ans = solveUsingRec(coins,amount-coins[i]);
            if(ans != INT_MAX){
                mini = min(mini,1 + ans);
            }
        }
        // cout<<"For this amount "<<amount<<" min no. of coins is "<<mini<<endl;
        return mini;
    }

    int solveMem(vector<int>& coins, int amount,vector<int>&dp){
        if(amount  == 0){
            return 0;
        }
        if(amount < 0){
            return INT_MAX;
        }

        // step 3: check in dp array:
        if(dp[amount]!= -1){
            return dp[amount];
        }


        int mini = INT_MAX;
        // 1 case:
        for(int i = 0;i<coins.size(); i++){
            int ans = solveMem(coins,amount-coins[i],dp);
            if(ans != INT_MAX){
                mini = min(mini,1 + ans);
            }
        }
        // cout<<"For this amount "<<amount<<" min no. of coins is "<<mini<<endl;
        dp[amount] = mini;
        return mini;
    }

int SolveTab(vector<int>& coins, int amount){
        // step 1 : create dp array:
        vector<int>dp(amount+1,INT_MAX);
        // step 2: check base case:
        dp[0] = 0;

        // step 3 : 1 to amount - range;
        for(int i = 1;i<=amount;i++){

            for(int j = 0;j<coins.size(); j++){
                if(i- coins[j] >= 0 && dp[i-coins[j]] != INT_MAX){
                    int ans = dp[i-coins[j]];
                    dp[i] = min(dp[i],1 + ans);
                }   
            }
        }

        return dp[amount];
    }
    
    int coinChange(vector<int>& coins, int amount) {
        // int ans = solveUsingRec(coins,amount);
        // if(ans != INT_MAX){
        //     return ans;
        // }
        // else{
        //     return -1;
        // }
        // return -1;

        vector<int>dp(amount+1,-1);
    }

int main()
{
    vector<int>coins = {1,2};
    int amount = 3;
    cout<<coinChange(coins,amount)<<endl;

 return 0;
}