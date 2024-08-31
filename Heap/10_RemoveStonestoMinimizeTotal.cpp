#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>maxHeap;

        for(int i = 0;i<piles.size();i++){
            maxHeap.push(piles[i]);
        }
        while(k--){
            int maxElement = maxHeap.top();
            maxHeap.pop();
            maxElement = maxElement - floor(maxElement/2);
            maxHeap.push(maxElement);
        }
        int sum = 0;
        while(!maxHeap.empty()){
            int top = maxHeap.top();
            sum += top;
            maxHeap.pop();
        }
    return sum;
    }
};

int main()
{

 return 0;
}