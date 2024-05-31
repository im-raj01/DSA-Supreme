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

class Solution {
public:

    int height(TreeNode* root){
    if(root == NULL){
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    int ans = max(leftHeight,rightHeight)+1;
    return ans;
}
    int diameterOfBinaryTree(TreeNode* root) {
        
        if(root == NULL){
            return 0;
        }

        int op1 = diameterOfBinaryTree(root->left);
        int op2 = diameterOfBinaryTree(root->right);

        int op3 = height(root->left) + height(root->right);
        int ans = max(op1,max(op2,op3));
        return ans;

    }
};//O(n^2)

class Solution {
public:
    pair<int,int>Fastdiameter(TreeNode* root){
        if(root == NULL ){
            // return 0;
            // diameter,height
            pair<int,int>p = make_pair(0,0);
            return p;
        }
        // left call 
        pair<int,int>left = Fastdiameter(root->left);
        pair<int,int>right = Fastdiameter(root->right);

        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second+right.second+1;

        pair<int,int>ans;
        ans.first = max(op1,max(op2,op3));
        ans.second = max(left.second,right.second)+1;
        return ans;
    }
    int diameterOfBinaryTree(TreeNode* root) {
              return Fastdiameter(root).first-1;
    }
};

int main()
{

 return 0;
}