// https://www.geeksforgeeks.org/problems/print-a-binary-tree-in-vertical-order/1
// Brute force:
// Vertical order Traversal of a tree;


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

void levelOrderTraversal(Node* root){
    queue<Node*>q;

    //inititally
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
      
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            //purana level complete ho chuka hai.
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
       else{
        cout<<temp->data<<" ";

       
        if(temp->left){
            q.push(temp->left);
        }
         if(temp->right){
            q.push(temp->right);
        }
       }
    }

}

void findMinMax(Node* root,int hd,int &min,int &max){
     if(root == NULL)
        return;
    if(hd < min)min = hd;
    if(hd > max)max = hd;

    //left and right me nikal lo
    findMinMax(root->left,hd-1,min,max);
    findMinMax(root->right,hd+1,min,max);
}

void printVerticalLine(Node* root, int lineNo, int hd){
    if(root == NULL)return;
    if(hd == lineNo)cout<<root->data<<" ";
    printVerticalLine(root->left,lineNo,hd-1);
    printVerticalLine(root->right,lineNo,hd+1);
}
void verticalOrder(Node* root){
    int min = 0;
    int max = 0;
    int hd = 0;
    findMinMax(root,hd,min,max);

    //i == lineno
    for(int i = min;i<=max;i++){
        printVerticalLine(root,i,0);
        // cout<<endl;
    }
}

int main()
{
    Node* root = NULL;

    root = buildTree();
    levelOrderTraversal(root); 
    cout<<"printing vertical order"<<endl;
    verticalOrder(root);
    
 return 0;
}
//Better

//Optimal
class Solution{

public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        vector<int>ans;
        if(root == NULL)
            return ans;
        map<int, map<int,vector<int> > > nodes;//hd , lvl --> list;
        queue<pair<Node*,pair<int,int> > > q; // hd,lvl
        
        q.push(make_pair(root,make_pair(0,0)));
        
        while(! q.empty()){
            pair<Node*,pair<int,int> > temp = q.front();
            q.pop();
            
            Node* frontNode = temp.first;
            int hd = temp.second.first;
            int lvl = temp.second.second;
            
            nodes[hd][lvl].push_back(frontNode->data);
            
            if(frontNode->left){
                q.push(make_pair(frontNode->left,make_pair(hd-1,lvl+1)));
            }
            if(frontNode->right){
                q.push(make_pair(frontNode->right,make_pair(hd+1,lvl+1)));
            }
        }
        
        for(auto i: nodes){
            for(auto j:i.second){
                
                for(auto k: j.second){
                    ans.push_back(k);
                }
            }
        }
        return ans;
    }
};
