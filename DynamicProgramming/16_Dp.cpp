#include<bits/stdc++.h>
using namespace std;
#define ll long long

// starting n-1
int solveUsingRec(int index,vector<int>&arr,int totalSum,int &mini){
    if(index < 0){
        return 0;
    }
    // int mini = INT_MAX;
    int Take = arr[index] + solveUsingRec(index-1,arr,totalSum,mini);
    int s1 = Take;
    int s2 = totalSum - Take;
    cout<<" At index "<<index<<" s1 is "<<s1<<endl;
    cout<<" At index "<<index<<" s2 is "<<s2<<endl;
    cout<<endl;
    int diff= abs(s1 - s2);
    mini = min(mini,diff);
    int NotTake = 0 + solveUsingRec(index-1,arr,totalSum,mini);

    return max(Take,NotTake);


}

int main()
{
    vector<int>arr={1,2,3};
    int n = arr.size();
    int totalSum = 0;
    int s1 = 0;
    int mini = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        totalSum += arr[i];
    }
    
    cout<<solveUsingRec(n-1,arr,totalSum,mini) << " is the ans"<<endl;
    cout<<mini<<endl;
 return 0;
}