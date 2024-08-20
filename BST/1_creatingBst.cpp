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
Node* insertIntoBST(Node* &root,int data){
    if(root == NULL){
        // this is going to be our first node
        root = new Node(data);
        return root;
    }
    // agar pehla node nhi hoga to :
    if(root->data > data){
        root->left = insertIntoBST(root->left,data);
    }
    else{
        root->right = insertIntoBST(root->right,data);
    }
    return root;
}

void takeInput(Node* &root){
    int data; 
    cin>>data;
    while (data != -1)
    {
        root = insertIntoBST(root,data);
        cin>>data;
    }
    
}

void levelOrderTraversal(Node* &root){
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

void printInorder(Node* &root){
    //LNR;
    if(root == NULL){
        return;
    }
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
    return;
}
void printPreorder(Node* &root){
    //LNR;
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";

    printInorder(root->left);
    printInorder(root->right);
    return;
}

void printPostorder(Node* &root){
    //LNR;
    if(root == NULL){
        return;
    }
    printInorder(root->left);
    printInorder(root->right);
    cout<<root->data<<" ";

    return;
}

int main()
{
    Node* root = NULL;
    cout<<"Enter the data for Node "<<endl;
    takeInput(root);
    cout<<"Print the BST Created: "<<endl;
    levelOrderTraversal(root);
    cout<<endl;
    cout<<"print inorder traversal:"<<endl;
    printInorder(root);
    cout<<endl;

    cout<<"print preorder traversal:"<<endl;
    printPreorder(root);
    cout<<endl;

    cout<<"print postorder traversal:"<<endl;
    printPostorder(root);
    cout<<endl;

 return 0;
}