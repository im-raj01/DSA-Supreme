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
/*
bool isCircular(Node* &head){
    if(head == NULL){
        return true;
    }
    Node* temp = head;
    Node* curr = head->next;

    while(curr != NULL){
        if(curr == temp){
            return true;
        }
        curr = curr->next;
    }
    return false;

}

bool isCircular(Node* head){
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

*/

// Using Hashing Map:
bool DetectCycle(Node* &head){
    unordered_map<Node*,bool>mpp;

    Node* temp = head;
    while(temp != NULL){
        if(mpp.find(temp) != mpp.end()){
            return true;
        }
        mpp[temp] = true;
        temp = temp->next;
    }
    return false;
}
// Using FCD(floyd cycle detection method):

bool checkForLoop(Node* &head){
    if(head == NULL){
        return true;
    }
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        if(slow == fast){
            return true;
        }
    }
    return false;
}

// Find Starting point of loop
Node* startingPointOfLoop(Node* &head){
    if(head == NULL){
        return NULL;
    }
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        if(slow == fast){
            slow = head;
            break;
        }
    }
    
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }
    return slow;
    
}
 
// remove loop:
Node* removeLoop(Node* &head) {
        if(head == NULL) {
                cout << "LL is empty "<< endl;
                return NULL;
        }

        Node* slow = head;
        Node* fast = head;
        Node* prev;
        while(fast != NULL) {
                fast = fast -> next;
                if(fast != NULL) {
                        fast = fast -> next;
                        prev = slow;
                        slow = slow -> next;
                }
                
                if(slow == fast ) {
                       slow = head;
                       break;
                }
        }
        if(slow == head){
            //last node jo h first se connected h:
            prev->next = NULL;
            return slow;
        }
        prev = fast;
        while(slow != fast) {
                prev = fast;
                slow = slow -> next;
                fast =fast -> next;
        }
        prev -> next = NULL;
        return slow;
}

int main()
{
    Node* head = new Node(15);
    Node* second = new Node(25);
    Node* third = new Node(35);
    Node* fourth = new Node(45);
    Node* fifth = new Node(55);
    Node* sixth = new Node(65);
    Node* seventh = new Node(75);
    Node* eigth = new Node(85);
    Node* ninth = new Node(95);


    head->next = second;
    second->next= third;
    third->next = fourth;
    fourth->next = head;
    // fifth->next = sixth;
    // sixth->next = seventh;
    // seventh->next = eigth;
    // eigth->next = ninth;
    // ninth->next = head;
    // printLL(head);
    // cout<<"cycle is present or NOt: "<<DetectCycle(head);
    cout<<"cycle is present or NOt: "<<checkForLoop(head)<<endl;
    cout<<"Starting point of lOOp is: "<<startingPointOfLoop(head)->data<<endl;
    removeLoop(head);
    printLL(head);




 return 0;
}
