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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL){
            return NULL;
        }
        if(root == p || root == q){
            return root;
        }
        TreeNode* leftAns = lowestCommonAncestor(root->left,p,q);
        TreeNode* rightAns = lowestCommonAncestor(root->right,p,q);
        if(leftAns == NULL && rightAns == NULL )return NULL;
        if(leftAns != NULL && rightAns == NULL )return leftAns;
        if(leftAns == NULL && rightAns != NULL )return rightAns;
        if(leftAns != NULL && rightAns != NULL )return root;

        return NULL;

    }
};


int main()
{

 return 0;
}