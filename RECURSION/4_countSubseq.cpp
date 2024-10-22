#include<bits/stdc++.h>
using namespace std;
#define ll long long

int countSubsequence(int ind,int sum , int target, vector<int>&arr){
    //base case:
    if(ind >= arr.size()){
        if(target == sum){
            //condition satisfies
            return 1;
        }
        //cond not satisfies
        else
        return 0;
    }
    //hr index pe :
    sum += arr[ind];
    
    int left = countSubsequence(ind+1,sum,target,arr);

    sum -= arr[ind];
    int right = countSubsequence(ind+1,sum,target,arr);
    return left + right;
}
int main()
{
    vector<int>arr= {1,2,1
    };
   
    int target = 2;
    int sum = 0;
    cout<<countSubsequence(0,sum,target,arr);
 return 0;
}