// Check if LL is Circular
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
    while (temp != NULL)
    {
        cout<<temp->data <<" ";
        temp = temp->next;
    }
    
}

// bool isCircular(Node* &head){
//     if(head == NULL){
//         return true;
//     }
//     Node* temp = head;
//     Node* curr = head->next;

//     while(curr != NULL){
//         if(curr == temp){
//             return true;
//         }
//         curr = curr->next;
//     }
//     return false;

// }

bool isCircular(Node* &head){
    if(head == NULL){
        return true;
    }
    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL && fast->next != NULL){
        if(slow == fast){
            return true;
        }
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}
int main()
{
    Node* head = new Node(15);
    Node* second = new Node(25);
    Node* third = new Node(35);
    Node* fourth = new Node(45);
    Node* fifth = new Node(55);
    Node* sixth = new Node(65);

    head->next = second;
    second->next= third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = head;
    // printLL(head);
    cout<<isCircular(head);



 return 0;
}
