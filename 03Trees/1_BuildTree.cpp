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

    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();
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
int main()
{
    Node* root = NULL;
    root = BuildTree();

    levelOrderTraversal(root);


 return 0;
}