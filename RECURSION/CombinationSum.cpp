#include <bits/stdc++.h>
using namespace std;
#define ll long long

void Solve(int index, vector<int> &candidates, int target, vector<vector<int>> &ans,
           vector<int> &temp)
{
    // Base case:
    if (index >= candidates.size())
    {
        if (target == 0)
        {
            ans.push_back(temp);
        }
        return;
    }

    // pick:
    if (candidates[index] <= target)
    {
        temp.push_back(candidates[index]);
        Solve(index, candidates, target - candidates[index], ans, temp);
        temp.pop_back();
    }
    // Not pick:
    Solve(index + 1, candidates, target, ans, temp);
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> temp;
    int ind = 0;
    Solve(ind, candidates, target, ans, temp);
    return ans;
}

int main()
{
    vector<int>arr = {2,3,6,7};
    int target = 7;

    vector<vector<int>>ans = combinationSum(arr,target);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
        
    }
    

    return 0;
}