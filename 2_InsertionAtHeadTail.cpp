// Insertion a node at head and tail
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

    Node(){
        this->data = 0;
        this->next =NULL;
    }
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

};
void printLL(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }

}

void InsertAthead(Node* &head,Node* &tail,int data){
     if(head == NULL){
       Node* newNode = new Node(data);
       head = tail = newNode;
       return;  
     }
     Node* newNode = new Node(data);
     newNode->next = head;
     head = newNode;
}

void InsertAtTail(Node* &tail,Node* &head,int data){

    if(head == NULL){
       Node* newNode = new Node(data);
       head = tail = newNode;
       return;  
     }
    // step 1 : create a newnode
    Node* newNode = new Node(data);

    // step2 : tail ko point kar diya newnode pe 
    tail->next = newNode;
    tail = newNode;
}

int main(){
   Node *head = NULL;
   Node *tail = NULL;
  
    InsertAthead(head,tail,70);
    InsertAthead(head,tail,50);
    InsertAthead(head,tail,30);
    InsertAthead(head,tail,20);
    InsertAtTail(tail,head,80);

    cout<<"After inserting at head"<<endl;
    printLL(head);
}

// jab bhi empty LL me node add ho to head and tail ko update karna jaroori hai.
