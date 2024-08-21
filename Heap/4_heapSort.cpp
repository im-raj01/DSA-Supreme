#include<bits/stdc++.h>
using namespace std;
#define ll long long

void heapify(int arr[], int n , int i){
    int index = i;
    int largest = index;
    int leftIndex = 2*index;
    int rightIndex = 2*index +1;

    if(leftIndex <= n && arr[leftIndex] > arr[largest]){
        largest = leftIndex;
    }
    if(rightIndex <= n && arr[rightIndex] > arr[largest]){
        largest = rightIndex;
    }
    if(index != largest){
        swap(arr[index],arr[largest]);
        index = largest;
        heapify(arr, n, index);
    }
}

void buildHeap(int arr[], int n){
    for(int i = n/2; i>0;i--){
        heapify(arr,n,i);
    }
}

void heapSort(int arr[], int n){
    int index = n;

    while (n != 1)
    {
        swap(arr[1],arr[index]);
        index--;
        n--;
        heapify(arr, n, 1);
    }
    
}
int main()
{
    int arr[] = {-1,12,15,13,11,14};
    int n = 5;
    buildHeap(arr, n);
    cout<<"printing the heap"<<endl;
    for (int i = 0; i <= n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    heapSort(arr,n);
    cout<<"printing after heapsort"<<endl;
    for (int i = 0; i <= n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    

 return 0;
}