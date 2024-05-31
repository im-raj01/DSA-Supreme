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
    bool mirrorImg(TreeNode* p, TreeNode* q){
        //if both are emtpy
        if(!p && !q){
            return true;
        }
        //if one is Null
        if(!p || !q){
            return false;
        }
        bool ans1 = (p->val == q->val);
        bool ans2 = mirrorImg(p->left,q->right);
        bool ans3 = mirrorImg(p->right,q->left);

        return (ans1 && ans2 && ans3);

    }
    bool isSymmetric(TreeNode* root) {
        if(!root){
            return true;
        }
        return mirrorImg(root->left,root->right);
    }
};
int main()
{

 return 0;
}