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


int findPositionFromInorder(int arr[],int n, int element){
    for (int i = 0; i < n; i++)
    {
        if(arr[i] == element){
            return i;
        }
    }
    return -1;  
}

unordered_map<int,int>mp;
void findPosUsingMap(int arr[],int n){
    for (int i = 0; i < n; i++)
    {
        mp[arr[i]] = i;
    }
    
}
// build tree from inorder and preorder:
/*
Node* buildTreeFromInorderPreorder(int inorder[],int preorder[],int size,
            int &preidx,int inorderStart,int inorderEnd){
    // base Case:
    if(preidx >= size || inorderStart > inorderEnd){
        return NULL;
    }
    // step A:
    int element = preorder[preidx++];
    // create root node:
    Node* root = new Node(element);

    int pos = mp[element];
    cout<<"pos for this "<<pos<<endl;

    // now for left and right call:
    root->left = buildTreeFromInorderPreorder(inorder,preorder,size,preidx,inorderStart,pos-1);
    root->right = buildTreeFromInorderPreorder(inorder,preorder,size,preidx,pos+1,inorderEnd);

    return root;



 }
*/

Node* buildTreeFromInorderPostOrder(int inorder[],int postorder[],int size,int &postIdx,
    int inorderStart,int inorderEnd){
    
    // base case:
    if(postIdx < 0 || inorderStart > inorderEnd){
        return NULL;
    }

    //create root node:
    int element = postorder[postIdx--];
    Node* root = new Node(element);

    //find pos:
    int pos = findPositionFromInorder(inorder,size,element);

    // step B; right call: 
    root->right = buildTreeFromInorderPostOrder(inorder,postorder,size,postIdx,pos+1,inorderEnd);
    root->left = buildTreeFromInorderPostOrder(inorder,postorder,size,postIdx,inorderStart,pos-1);

    return root;
            
}
int main()
{
    int size = 7;
    int inorder[] = {40,20,50,10,60,30,70};
    int postorder[] = {40,50,20,60,70,30,10};
    int preIdx = 0;
    int postIdx = size-1;
    findPosUsingMap(inorder,size);
    // Node* root =  buildTreeFromInorderPreorder(inorder,preorder,size,preIdx,0,size-1);

    Node* root = buildTreeFromInorderPostOrder(inorder,postorder,size,postIdx,0,size-1);

    cout<<"level order traversal:"<<endl;
    levelOrderTraversal(root);


 return 0;
}