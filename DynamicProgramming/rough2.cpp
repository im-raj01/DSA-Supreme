// reverse ll in a grp of K Nodes. 
#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Node{
    public:
    int data;
    Node* next;

    Node(){
        this->data = 0;
        this->next = NULL;
    }

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void printLL(Node* &head){
    Node* temp = head;
    while (temp!= NULL)
    {
        /* code */
        cout<<temp->data <<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int getlength(Node* &head){
    Node* temp = head;
    int len = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}



Node* reverseKnodes(Node* &head,int k){
    if(head == NULL){
        //ll empty
        cout<<"LL is empty"<<endl;
        return NULL;
    }
    int len = getlength(head);
    
    if(k> len){
        cout<<"Enter valid value for k"<<endl;
        return head;
    }

    //now k>len 
    //step A : reverse first k Nodes of LL
    Node* prev = NULL;
    Node* curr = head;
    Node* forward;
    int count = 0;

    while(count < k){
        forward = curr->next;
        curr->next = prev;

        prev = curr;
        curr = forward;
        count++;
    }
    //step B:rec call
    if(forward != NULL){
        // we still have nodes left to reverse
        // cout<<forward->data<<endl;
        // cout<<curr->data<<endl;

        head->next = reverseKnodes(forward,k);
    }

    // step c: return head of modified ll
    return prev;

}
int main()
{
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(40);
    Node* fifth = new Node(50);
    Node* sixth = new Node(60);


    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;


    printLL(head);
    cout<<"after reverse"<<endl;
    head = reverseKnodes(head,4);
    printLL(head);



 return 0;
}