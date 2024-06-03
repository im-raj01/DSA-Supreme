#include<bits/stdc++.h>
using namespace std;
#define ll long long
/*
bool solve(Node *root,int &k,int node,int &ans){
    if(root == NULL){
        return false;
    }
    // search node:
    if(root->data == node){
        return true;
    }
    
    bool leftAns = solve(root->left,k,node,ans);
    bool rightAns = solve(root->right,k,node,ans);
    
    if(leftAns || rightAns){
        // cout<<"k decreases by 1"<<endl;
        k--;
    }
    if(k == 0){
        ans = root->data;
        // cout<<"ans is; " <<ans<<endl;
        k = -1;
    }
    return leftAns || rightAns;
    
}
int kthAncestor(Node *root, int k, int node)
{
    // Code here
    int ans = -1;
    solve(root,k,node,ans);
    return ans;
    
    
}

*/
int main()
{

 return 0;
}