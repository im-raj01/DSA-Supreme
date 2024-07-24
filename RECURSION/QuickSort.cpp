#include <bits/stdc++.h> 
using namespace std;


int partitionInd(vector<int>&arr,int low,int high){
    int pivot = arr[low];
    int i = low, j=high;
    while(i < j){
        while(arr[i] <= pivot && i <= high){
            i++;
        }
        while(arr[j] > pivot && j >= low){
            j--;
        }
        if(i < j){
            swap(arr[i],arr[j]);

        }
    }
    swap(arr[low],arr[j]);
    return j;
}

void qS(vector<int>&arr,int low, int high){
    if(low < high){
        int partitionIndex = partitionInd(arr,low,high);
        qS(arr,low,partitionIndex-1);
        qS(arr,partitionIndex+1,high);
    }
}
vector<int> quickSort(vector<int> arr)
{
    // Write your code here.
    qS(arr,0,arr.size()-1);
    return arr;
}
int main(){


    
    return 0;
}
