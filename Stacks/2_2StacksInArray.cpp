#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Stack{
    public:
    int *arr;
    int index1;
    int index2;
    int size;

    // functions:: --> push1, pop1, top1, push2,pop2, top2;
    Stack(int size){
        arr = new int[size];
        this->size = size;
        index1 = -1;
        index2 = size;

    }
    // functions:
    void push1(int data){
        if(index2 - index1 > 1){
            // space available so we can insert:
            index1++;
            arr[index1] = data;
        }
        else{
            cout<<"Stack Overflow so we cannot insert new items"<<endl;
        }
    }
    void push2(int data){
        if(index2 - index1 > 1){
            // space available so we can insert:
            index2--;
            arr[index2] = data;
        }
        else{
            cout<<"Stack Overflow so we cannot insert new items"<<endl;
        }
    }

    void pop1(){
        //  
        if(index1 == -1){
            cout<<"No elements is present in stack 1 "<<endl;
        }
        else{
            index1--;
        }
    }
    void pop2(){
        //  
        if(index2 == size){
            cout<<"No elements is present in stack 2 "<<endl;
        }
        else{
            index2++;
        }
    }

    int getTop1(){
        if(index1 == -1){
            cout<<"No element is present in stack1"<<endl;
        }
        else{
            return arr[index1];
        }
        return 0;
    }

    int getTop2(){
        if(index2 == size){
            cout<<"No element is present in stack2"<<endl;
        }
        else{
            return arr[index2];
        }
        return 0;
    }
};
int main()
{
    Stack s(10);

    //insert elements;
    s.push1(10);
    s.push1(20);
    s.push1(30);

    s.push2(100);
    s.push2(90);

    s.push1(40);
    s.push1(50);
    s.push1(60);

    s.push2(80);
    s.push2(70);
    // s.push2(120);
    s.pop1();
    s.pop2();


    cout<<"Top element of stack1 "<<s.getTop1()<<endl;
    cout<<"Top element of stack2 "<<s.getTop2()<<endl;




 return 0;
}