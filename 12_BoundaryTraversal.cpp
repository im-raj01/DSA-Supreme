//https://www.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1
class Solution {
public:
    void TraverseLeft(Node *root, vector<int>&ans){
        if(root == NULL || (root->left == NULL && root->right == NULL)){
            return ;
        }
        ans.push_back(root->data);
        
        if(root->left){
            TraverseLeft(root->left,ans);
        }
        else{
            TraverseLeft(root->right,ans);
        }
    }
    void TraverseLeaf(Node *root,vector<int>&ans){
        if(root == NULL)return;
        if(root->left == NULL && root->right == NULL){
            ans.push_back(root->data);
            return;
        }
        TraverseLeaf(root->left,ans);
        TraverseLeaf(root->right,ans);
    }
    void TraverseRight(Node *root,vector<int>&ans){
        if(root == NULL || (root->left == NULL && root->right == NULL)){
            return ;
        }
        if(root->right)
            TraverseRight(root->right,ans);
        else
            TraverseRight(root->left,ans);
        ans.push_back(root->data);
    }
    
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector<int>ans;
        if(root == NULL){
            return ans;
        }
        ans.push_back(root->data);
        
        //left part ke liye call kar lo:
        TraverseLeft(root->left,ans);
        //leaf node ke liye:
        TraverseLeaf(root->left,ans);
        TraverseLeaf(root->right,ans);
        
        //right part ke liye:
        TraverseRight(root->right,ans);
        
        return ans;
    }
};
