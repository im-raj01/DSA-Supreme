#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Stack{
    public:
    int *arr;
    int top; // yahan pe ye array ka index ka kaam kar raha h
    int size;

    // function: --> push() pop() top(), size(),empty():
    Stack(int size){
        arr = new int[size];
        this->size = size;
        top = -1;
    }

    //functions:
    void push(int data){
        if(size - top > 1){
            // size available hai array ya stack me :
            top ++;
            arr[top] = data;
        }
        else{
            cout<<"Stack Overflow"<<endl;
        }
    }

    void pop(){
        // agar stack empty hua to 
        if(top == -1){
            cout<<"Stack empty == stack underflow"<<endl;
        }
        else{
            top--;
        }
    }
    int getTop(){
        if(top == -1){
            cout<<"No element is present in the stack"<<endl;
        }
        else{
            return arr[top];
        }
        return 0;
    }

    int getSize(){
        // return no. of elements in stack:
        return top+1;
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }
        else
            return false;
    }
};
int main()
{  
    // create an array of 10 size to implement stack:
    Stack s(10);

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    while (!s.isEmpty())
    {
        cout<<s.getTop()<<" ";
        s.pop();
    }
    cout<<endl;
    cout<<"size after pop all "<<s.getSize()<<endl;
    
 return 0;
}