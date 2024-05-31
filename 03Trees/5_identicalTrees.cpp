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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // if both trees are empty:
        if(p == NULL && q == NULL){
            return true;
        }
        //if one - empty and one not:
        if(p == NULL && q!= NULL || p!= NULL && q == NULL){
            return false;
        }
        //if non-empty:
        bool ans1 = (p->val == q->val);
        bool ans2 = isSameTree(p->left,q->left);
        bool ans3 = isSameTree(p->right,q->right);

        return (ans1 && ans2 && ans3);
    }
};
int main()
{

 return 0;
}