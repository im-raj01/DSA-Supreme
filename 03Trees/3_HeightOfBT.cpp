#include<bits/stdc++.h>
using namespace std;
#define ll long long
class TreeNode{
    public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode (int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};
int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int leftHeight = maxDepth(root->left);
        int rightHeight = maxDepth(root->right);
        int ans = 1 + max(leftHeight,rightHeight);

        return ans;
}
int main()
{
    TreeNode* root = NULL;
    maxDepth(root);

 return 0;
}