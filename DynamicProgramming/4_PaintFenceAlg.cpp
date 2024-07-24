#include<bits/stdc++.h>
using namespace std;
#define ll long long

long long mod = 1e9+7;
    // recursive code:
    long long SolveUsingRec(int n,int k){
         if(n == 1){
            return k;
            
        }
        if(n == 2){
            return (k+(k*(k-1)));
        }
        long long ans = ((SolveUsingRec(n-2,k)+SolveUsingRec(n-1,k))*(k-1))%mod;
        return ans;
    }
    
    long long SolveUsingMem(int n,int k, vector<long long>&dp){
        if(n == 1){
            return k;
            
        }
        if(n == 2){
            return (k+(k*(k-1)));
        }
        
        if(dp[n] != -1){
            return dp[n];
        }
        dp[n] = ((SolveUsingMem(n-2,k,dp)+SolveUsingMem(n-1,k,dp))*(k-1))%mod;
        return dp[n];
    }
    
    long long SolveUsingTab(int n,int k){
        vector<long long>dp(n+1,0);
        dp[1] = k;
        dp[2] = (k%mod * k%mod)%mod;
        
        for(int i = 3; i<= n; i++){
             dp[i] = ((dp[i-2] + dp[i-1])%mod * (k-1))%mod;
        }
        return dp[n];
    }
    
    
    
    
    
    long long countWays(int n, int k){
        // code here
        // return SolveUsingRec(n,k);
        
        // vector<long long>dp(n+1,-1);
        // long long ans = SolveUsingMem(n,k,dp);
        // return ans;
        
        long long ans3 = SolveUsingTab(n,k);
        return ans3;
       
    }
int main()
{

 return 0;
}