#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

int countNode(Node* root){
    if(root == NULL){
        return 0;
    }
    int leftAns = countNode(root->left);
    int rightAns= countNode(root->right);
    return 1+leftAns+rightAns;
}

bool isCBT(Node* root, int i,int n){
    if(root == NULL){
        return true;
    }
    if(i > n){
        return false;
    }
    bool leftAns = isCBT(root->left,2*i,n);
    bool rightAns = isCBT(root->right,2*i+1,n);
    return leftAns && rightAns;
}

bool maxOrder(Node* root){
    if(root == NULL)
        return true;
    bool l = maxOrder(root->left);
    bool r = maxOrder(root->right);
    bool ans = false;
    //now root 
    if(root->left == NULL && root->right == NULL){
        ans = true;
    }
    if(root->left && !root->right){
        ans = root->data > root->left->data;
    }
    if(root->left && root->right){
        ans = (root->data > root->left->data) && (root->data > root->right->data);
    }
    return l && r && ans;
}
class Solution {
  public:
    bool isHeap(struct Node* tree) {
         int n = countNode(tree);
         int i =1;
         return isCBT(tree,i,n) && maxOrder(tree);
    }
};

int main()
{

 return 0;
}