//A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

#include<bits/stdc++.h>
using namespace std;
#define ll long long

class TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode (int data){
        this->val = data;
        left = NULL;
        right = NULL;
    }
};

class Solution {
public:
    int height(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        return (1+max(leftHeight,rightHeight));
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL){
            return true;
        }

        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        bool rootAns = abs(leftHeight-rightHeight)<=1;

        bool leftAns = isBalanced(root->left);
        bool rightAns = isBalanced(root->right);

        return (rootAns && leftAns && rightAns);
    }
}; // O(N^2);

class Solution{
    public:
    pair<bool,int>CheckBalancedFast(TreeNode* root){
        if(root == NULL){
            // T, height
            pair<int,int>p = make_pair(true,0);
            return p;
        }

        pair<bool,int>left = CheckBalancedFast(root->left);
        pair<bool,int>right = CheckBalancedFast(root->right);

        bool leftAns = left.first;
        bool rightAns = right.first;
        bool rootAns = abs(left.second - right.second) <=1;

        pair<bool,int>ans;
        ans.first = (leftAns && rightAns && rootAns);
        ans.second = max(left.second,right.second)+1;
        return ans;
    }
    bool isBalanced(TreeNode* root){

    }
};


int main()
{

 return 0;
}