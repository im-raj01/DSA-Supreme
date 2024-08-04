//Remove Duplicates :
//Sorted LL::
#include <iostream>
using namespace std;

class Node{
        public:
        int data;
        Node* next;

        Node(int data) {
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

Node* removeDuplicates(Node* &head){
      if(head == NULL){
        cout<<"LL is empty"<<endl;
        return NULL;
      }
      if(head->next == NULL){
        return head;
      }
      cout<<"remove fun is called "<<endl;
      //agar 1 se jyada node present ho to:
      Node* prev = NULL;
      Node* curr = head;
      Node* fwd = head->next;
      while (curr != NULL && curr->next != NULL)
      {
      cout<<"inside while loop "<<endl;

        fwd = curr->next;
        if(curr->data != fwd->data){
                //delete nhi karna h:
      cout<<"inside not equal to "<<endl;

                curr = fwd;
        }
        else{
            cout<<" curr is equal to fwd "<<endl;
                Node* temp = fwd;
                curr->next = fwd->next;
                temp->next = NULL;
                delete(temp);


        }
      }
      return head;
      
}

int main() {
  Node* head = new Node(10);
  Node* second = new Node(1);
  Node* third = new Node(1);
  Node* fourth = new Node(10);
  Node* fifth = new Node(20);
  Node* sixth = new Node(20);
  head -> next = second;
  second -> next = third;
  third -> next = fourth;
  fourth -> next = fifth;
  fifth -> next = sixth;
  sixth->next = NULL;
cout<<"before deletion:"<<endl;
print(head);
cout<<endl;
  head = removeDuplicates(head);
  cout<<"after deletion:"<<endl;
  print(head);

  return 0;
}

// UNSORTED LL::
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node *removeDuplicates(Node *&head)
{
    if (head == NULL)
    {
        return head;
    }
    if(head->next == NULL){
        return head;
    }
    // agar node 1 se bada hoga
    Node* curr = head;
    while(curr != NULL && curr->next != NULL){
        Node* ptr2 = curr;
        while (ptr2->next != NULL)
        {
            if (curr->data == ptr2->next->data)
            {
                Node* dup = ptr2->next;
                ptr2->next = ptr2->next->next;
                dup->next = NULL;
                delete dup;
            }
            else{
                ptr2 = ptr2->next;
            }
               
        }
        curr = curr->next;
        
    }
    return head;
    
     
}

int main()
{
    Node *head = new Node(12);
    Node *second = new Node(11);
    Node *third = new Node(12);
    Node *fourth = new Node(21);
    Node *fifth = new Node(41);
    Node *sixth = new Node(43);
    Node *seventh = new Node(41);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = NULL;
    cout << "before deletion:" << endl;
    print(head);
    cout << endl;
    head = removeDuplicates(head);
    cout << "after deletion:" << endl;
    print(head);

    return 0;
}

// 2nd method:
