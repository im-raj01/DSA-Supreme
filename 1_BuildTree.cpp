// Create a tree:
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
        left = NULL;
        right = NULL;
    }
};

Node* buildTree(){
    int data;
    cout<<"enter the data: "<<endl;
    cin>>data;
    if(data == -1){
        return NULL;
    }

    //step a,b and c;
    Node* root = new Node(data);

    cout<<"Enter data for left part: "<<endl;
    root->left = buildTree();

    cout<<"Enter data for right part: "<<endl;

    root->right = buildTree();

    return root;
}
// level order Traversal:
void levelOrderTraversal(Node* root){
    queue<Node*>q;

    //inititally push the root into Queue:
    q.push(root);

    while(!q.empty()){
        //A = temp me q ke front store kar lo
        Node* temp = q.front();
        //B = pop kar lo
        q.pop();
        //C - print node 
        cout<<temp->data<<" ";

        //D- child insert:
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

    root = buildTree();
    levelOrderTraversal(root); 

 return 0;
}
