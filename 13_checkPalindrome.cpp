// checK ll is palindrome or not:
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

void print(Node* &head){
    Node* temp = head;
    while (temp!= NULL)
    {
        cout<<temp->data<<" ";
        temp = temp->next;

    }
} 

Node* reverse(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    Node* fwd = head->next;

    while (curr != NULL)
    {
        fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
    }
    return prev;
    
}

bool checkPalindrome(Node* &head){
    if(head == NULL){
        return true;

    }
    if(head->next == NULL){
        return true;
    }
    //ll>1:
    //step A : find middle:
    Node* slow = head;
    Node* fast = head->next;
    while (fast != NULL && fast->next!= NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    //slow pointer is on the middle node:

    // step B: reverse LLL after middle/slow node:
    Node* reverseLLKaHead = reverse(slow->next);

    slow->next = reverseLLKaHead;
    // start comparing:
    Node* temp1 = head;
    Node* temp2 = reverseLLKaHead;
    while (temp2!=NULL)
    {
        if(temp1->data != temp2->data){
            return false;
        }
        temp1 = temp1->next;
        temp2 = temp2->next;
    }
    return true;
    
}
int main()
{
    Node* head = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
    Node* fourth = new Node(30);
    Node* fifth = new Node(20);
    Node* sixth = new Node(10);
   
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = NULL;

    bool isPalindrome = checkPalindrome(head);
     if(isPalindrome) {
          cout << "LL is a valid palindrome" << endl;
    }
    else {
            cout << "LL is not a palindrome" << endl;
    }


}
