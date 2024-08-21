#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Heap{
    public:
    int arr[101];
    int size;
    Heap(){
        size = 0;
    }
    void insert(int value){
        // value insert end me karo
        size = size + 1;
        int index = size;
        arr[index] = value;

        // iss value ko sahi jagah pe le jao:
        while (index > 1)
        {
            int parentIndex = index/2;
            if(arr[index] > arr[parentIndex]){
                swap(arr[index],arr[parentIndex]);
                index = parentIndex;
            }
            else{
                break;
            }
        }
    }

    int deletion(){
        // replace root value with last node value
        arr[1] = arr[size];
        int ans = arr[1];
        size--;
        // place root value at correct position:
        int index = 1;
        while(index < size){
            int left = 2* index;
            int right = 2* index+1;

            int largest = index;
            if(left < size && arr[largest] < arr[left]){
                largest = left;
            }
            if(right < size && arr[largest] < arr[right]){
                largest = right;
            }

            if(largest == index){
                // value is at correct position;
                // return ;
                break;
            }
            else{
                swap(arr[index],arr[largest]);
            }
            index = largest;
            
        }
        return ans;
    }
};
int main()
{
    Heap h;
    // h.arr[0] = -1;
    // h.arr[1] = 100;
    // h.arr[2] = 50;
    // h.arr[3] = 60;
    // h.arr[4] = 40;
    // h.arr[5] = 45;

    // h.size = 5;
    

    h.insert(50);
    h.insert(30);
    h.insert(70);
    h.insert(40);
    h.insert(80);
    h.insert(100);

    cout<<"printing the heap"<<endl;
    for (int i = 0; i <= h.size; i++)
    {
        cout<<h.arr[i]<<" ";
    }
    cout<<endl;
    // h.insert(110);
    cout<<"printing the heap after insertion: "<<endl;
    for (int i = 0; i <= h.size; i++)
    {
        cout<<h.arr[i]<<" ";
    }
    cout<<endl; 

    int deletedElement = h.deletion();
    cout<<"printing the heap after deletion: "<<endl;
    for (int i = 0; i <= h.size; i++)
    {
        cout<<h.arr[i]<<" ";
    }



 return 0;
}