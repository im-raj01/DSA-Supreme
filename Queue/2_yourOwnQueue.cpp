#include<iostream>
using namespace std;

class Queue{
    public:
    int *arr;
    int size;
    int front;
    int rear;

    Queue(int size){
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }
    //methods;
    void push(int data){
        if(rear == size){
            cout<<"Q is Full"<<endl;
        }
        else{
            arr[rear] = data;
            rear++;
        }
    }
    void pop(){
        if(front == rear){
            cout<<"Q is empty"<<endl;
        }
        else{
            arr[front] = -1;
            front++;
            if(front == rear){
                // q empty ho chuka h
                front = 0;
                rear = 0;
            }
        }
    }
    int getFront(){
        if(front == rear){
            cout<<"q empty hai"<<endl;
            return -1;
        }
        else{
            return arr[front];
        }
    }

    bool isEmpty(){
        if(front == rear){
            return true;
        }
        else{
            return false;
        }
    }

    int getSize(){
        return rear - front;
    }
};

int main(){
    // creating a queue of size 8
    Queue q(10);
    //insertion:
    q.push(5);
    q.push(15);
    q.push(25);
    q.push(35);

    cout<<"size of q is "<<q.getSize()<<endl;
    q.pop();
    cout<<"size of q is "<<q.getSize()<<endl;

    cout<<"front element is "<<q.getFront()<<endl;
    

}