// DElete a Node
// insert a node at any position
// Insertion at head and tail

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

     ~Node() {
                //write your code here
                cout << "Node with value: " << this->data << "deleted" << endl;
     }

};

// print ll ka function:
void printLL(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }

}

// insert at head ka function:

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


//finding the length of the linked list:
int findLength(Node* head){
    int len = 0;
    Node* temp = head;
    while (temp!=NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}
// insert at any position 
void insertAtPosition(int position,int data,Node* &head,Node* &tail){
     // if LL is empty
     if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;
     }

     if(position == 0){
        InsertAthead(head,tail,data);
        return;
     }

     int len = findLength(head);
     cout<<"length of LL is: "<<len<<endl;
     if(position >= len){
        InsertAtTail(tail,head,data);
        return;
     }

     //step 1: find the prev and curr node
     int i = 1;
     Node* prev = head;
     while (i<position)
     {
        prev = prev->next;
        i++;
     }

     Node* curr = prev->next;

     // step 2: create a newnode
     Node* newNode = new Node(data);

     // step 3: newnode ko connect karo curr
     newNode->next = curr;

     // step 4: prev ke next ko newnode se connect kar do
     prev->next = newNode;
      

}

// delete a node 
void deleteNode(Node* &head,Node* &tail,int position){
    if(head == NULL){
        cout<<"LL is Empty, cannot be deleted"<<endl;
        return;
    }

    // head node ko delete karna hai to 
    if(position == 1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }

    // tail ko delete karna hai to
    int len = findLength(head);
    if(position == len){
    // find prev 
        Node* prev = head;
        int i=1;
        while (i< position-1)
        {
            prev = prev->next;
            i++;
        }
        Node* temp = tail;
        prev->next = NULL;
        tail = prev;
        delete temp;
        return;
    }

    // delete middle node:
    int i = 1;
    Node* prev = head;
    while (i<position-1)
    {
        prev = prev->next;
        i++;
    }
    Node* curr = prev->next;
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
    return;
    
}

int main(){
   Node *head = NULL;
   Node *tail = NULL;

    InsertAthead(head,tail,70);
    InsertAthead(head,tail,50);
    InsertAthead(head,tail,30);
    InsertAthead(head,tail,20);
    InsertAtTail(tail,head,80);


    printLL(head);
    cout<<endl;
    // insertAtPosition(0,155,head,tail);
    // cout<<"LL after inserting at position:"<<endl;
    // printLL(head);
    deleteNode(head,tail,2);
    cout<<"LL after deletion: "<<endl;
    printLL(head);
}
