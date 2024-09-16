#include<iostream>
using namespace std;

class Deque{
    public:
    int *arr;
    int size;
    int front;
    int rear;

    Deque(int size){
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    //methods;
    void pushRear(int data){
        // dequeue full
        //single element case:
        //circular nature
        //normal flow
        if((front == 0 && rear == size-1) || (rear == front-1)){
            cout<<"deque is full, cannot insert "<<endl;
        }
        else if(front == -1){
            front = rear = 0;
            arr[rear] = data;
        }
        else if(rear == size-1 && front != 0){
            rear = 0;
            arr[rear] = data;
        }
        else{
            rear++;
            arr[rear] = data;
        }
    }

    void pushFront(int data){
        if((front == 0 && rear == size-1) || (rear == front+1)){
            cout<<"deque is full, cannot insert "<<endl;
            return;
        }
        else if(front == -1){
            front = rear = 0;
        }
        else if(front == 0 && rear != size-1){
            front = size-1;;
        }
        else{
            front--;
        }
        arr[front] = data;
    }
    //now pop
    void popFront(){
        //empty check
        //single element
        //circular nature
        //normal flow:
        if(front == -1){
            cout<<"deque is empty, cannot pop"<<endl;
        }
        else if(front == rear){
            //single element is present:
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        else if(front == size-1){
            front = 0;
        }
        else{
            arr[front] = -1;
            front++;
        }
    }
    void popRear(){
        if(front == -1){
            cout<<"deque is empty, cannot pop"<<endl;
        }
        else if(front == rear){
            //single element is present:
            arr[front] = -1;
            front = -1;
            rear = -1;
        }
        else if(rear == 0){
            rear = size-1;
        }
        else{
            rear--;
        }
    }

    
    
};

int main(){
    // creating a queue of size 8
    

}