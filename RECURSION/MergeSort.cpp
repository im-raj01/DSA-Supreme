#include<bits/stdc++.h>
using namespace std;
#define ll long long

void merge(vector<int>&arr,int low,int mid,int high){
     vector<int>temp; //temp arr;
     //[low ... mid]  and [mid+1 ... high]
     int left = low;
     int right = mid+1;

     while (left <= mid && right <= high)
     {
      if(arr[left] <= arr[right]){
         temp.push_back(arr[left]);
         left++;
      }
      else{
         temp.push_back(arr[right]);
         right++;
      }
     }

     while (left <= mid)
     {
      temp.push_back(arr[left]);
      left++;
     }
     while(right <= high){
      temp.push_back(arr[right]);
      right++;
     }

     for (int i = low; i <= high; i++)
     {
      /* code */
      arr[i] = temp[i];
     }
     
     
     
}

void mS(vector < int > & arr, int low ,int high){
     if(low >= high){
        return;
     }
     int mid = low + (high-low)/2;
     mS(arr,low,mid);
     mS(arr,mid+1,high);

     merge(arr,low,mid,high);
}   
int main()
{

 return 0;
}
