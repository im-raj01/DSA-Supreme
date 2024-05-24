#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node (int data){
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

Node* BuildTree(){
    int data;
    cout<<"Enter the data: "<<endl;
    cin>>data;

    if (data == -1)
    {
        return NULL;
    }
    // steps - A ->create root node
    //    B -> root->left = rec call
    //    C-> root-right = rec call

    Node* root = new Node(data);

    cout<<"For left part, ";
    root->left = BuildTree();

    cout<<"For right part, ";
    root->right = BuildTree();

    return root;
    
}

void levelOrderTraversal(Node* root){
    queue<Node*>q;
    //initially push the root of the tree:
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        if(temp == NULL){
            // purana level complete ho chuka h :
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
    else{
        cout<<temp->data<<" ";

        // insertion of child nodes:
        if(temp->left){
            q.push(temp->left);
        }
        if(temp->right){
            q.push(temp->right);
        }
    }
    }   
}

void inorderTraversal(Node* root){
    // LNR
    // base case:
    if(root == NULL){
        return;
    }
    //left part call:
    inorderTraversal(root->left);
    //print the node:
    cout<<root->data<<" ";

    // right part call: 
    inorderTraversal(root->right);

}

void preorderTraversal(Node* root){
    // NLR
    // base case:
    if(root == NULL){
        return;
    }

    //print the node:
    cout<<root->data<<" ";

    //left part call:
    preorderTraversal(root->left);
    
    // right part call: 
    preorderTraversal(root->right);

}

void postorderTraversal(Node* root){
    // LRN
    // base case:
    if(root == NULL){
        return;
    }

    

    //left part call:
    postorderTraversal(root->left);
    
    // right part call: 
    postorderTraversal(root->right);

    //print the node:
    cout<<root->data<<" ";

}

int main()
{
    Node* root = NULL;
    root = BuildTree();

    levelOrderTraversal(root);
    cout<<"Inorder call Ans: "<<endl;
    inorderTraversal(root);
    cout<<endl;

    cout<<"preorder call Ans: "<<endl;
    preorderTraversal(root);
    cout<<endl;

    cout<<"postorder call Ans: "<<endl;
    postorderTraversal(root);


 return 0;
}