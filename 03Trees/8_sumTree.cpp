#include<bits/stdc++.h>
using namespace std;
#define ll long long
/*
class Solution
{
    public:
    int solveSum(Node* root){
        if(root == NULL){
            return 0;
        }
        int leftSum = solveSum(root->left);
        int rightSum = solveSum(root->right);
        
        return (leftSum+rightSum+root->data);
    }
    bool isSumTree(Node* root)
    {
         // Your code here
         if(root == NULL){
             return true;
         }
         // leaf case:
         if(root->left == NULL && root->right == NULL){
             return true;
         }
         // 1 case:
         int leftSum = solveSum(root->left);
         int rightSum = solveSum(root->right);
         int data = root->data;
        //  cout<<"leftsum is :"<<leftSum<<endl;
        //  cout<<"rightSum is: "<<rightSum<<endl;
         bool rootAns = (data == (leftSum + rightSum));
         //rec call
         bool leftAns = isSumTree(root->left);
         bool rightAns= isSumTree(root->right);
            
         return (rootAns && leftAns && rightAns);
         
         
         
    }
}
class Solution
{
    public:
    pair<bool,int>CheckSumFast(Node* root){
        // pair - sumTree(bool), sum
        if(root == NULL){
            pair<bool,int>p = make_pair(true,0);
            return p;
        }
        if(root ->left == NULL && root->right == NULL){
            // leaf node:
            pair<bool,int>p = make_pair(true,root->data);
            return p;
        }

        //rec call
        pair<bool,int>left = CheckSumFast(root->left);
        pair<bool,int>right = CheckSumFast(root->right);

        bool leftAns = left.first;
        bool rightAns = right.first;
        bool rootAns = (root->data == (left.second + right.second));

        pair<bool,int>ans;
        ans.first = (leftAns && rightAns && rootAns);
        ans.second = (left.second + right.second + root->data);
        return ans;


    }
    bool isSumTree(Node* root)
    {
         // Your code here
    }
};
*/
int main()
{

 return 0;
}