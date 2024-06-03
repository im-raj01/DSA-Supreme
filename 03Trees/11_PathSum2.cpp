#include<bits/stdc++.h>
using namespace std;
#define ll long long



 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 

class Solution {
public:
    bool checkLeafNode(TreeNode* root){
        if(!root->left && !root->right){
            return true;
        }
        return false;
    }
    void helper(TreeNode* root,int targetSum,vector<vector<int>>& ans,vector<int>&v,int &sum){
        // vector<int>v;
        if(root == NULL){
            return;
        }
        // cout<<"call for "<<root->val<<endl;

        // root ko vector me dalo
        v.push_back(root->val);
        sum += root->val;
        // cout<<" sum for this call "<<root->val <<"is :"<<sum <<endl;
        //leftCall
         helper(root->left,targetSum,ans,v,sum);
        // rightcall;
         helper(root->right,targetSum,ans,v,sum);

        if(sum == targetSum && checkLeafNode(root)){
            cout<<"sum is equal"<<endl;
            ans.push_back(v);

        }
        v.pop_back();
        sum -= root->val;

    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        vector<int>v;
        vector<vector<int>>ans;
        helper(root,targetSum,ans,v,sum);
        return ans;
    }
};
int main()
{

 return 0;
}