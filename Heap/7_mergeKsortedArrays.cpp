#include<bits/stdc++.h>
using namespace std;
#define ll long long
class info{
public:
    int data;
    int row;
    int col;
    info(int val,int r,int c){
        data = val;
        row = r;
        col = c;
    }
};

class compare{
public:
    bool operator()(info* a, info* b){
        return a->data > b->data;
         //  priority_queue in C++ is a max-heap, meaning it sorts elements in descending order (i.e., the largest element is at the top)
    }
};

vector<int>mergeKSortedArrays(int arr[][4],int k, int n){
    //create a min heap of size k
    priority_queue<info*,vector<info*>,compare> minHeap;
    // har array ka first element insert karo
    for (int i = 0; i < k; i++)
    {
        info* temp = new info(arr[i][0],i,0);
        minHeap.push(temp);
    }
    vector<int>ans;
    while (!minHeap.empty())
    {
        info* temp = minHeap.top();
        int topElement = temp->data;
        int topRow = temp->row;
        int topCol = temp->col;
        minHeap.pop();

        ans.push_back(topElement);
        if(topCol + 1 < n){
            info* newInfo = new info(arr[topRow][topCol+1],topRow,topCol +1);

            minHeap.push(newInfo);
        }
    }
    return ans;
    
    
}

int main()
{
    int arr[][4] = {{2,4,6,8},{1,3,5,7},{0,9,10,11}};
    int k = 3;
    int n = 4;
    vector<int>ans = mergeKSortedArrays(arr,k,n);
    for(auto i: ans){
        cout<<i<<" ";
    }

 return 0;
}