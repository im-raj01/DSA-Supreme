#include<bits/stdc++.h>
using namespace std;
#define ll long long

int signum(int a, int b){
    if(a == b)
        return 0;
    
    if(a > b)
        return 1;
    if(a < b)
        return -1;
   
}

void callMedianUsingSwitch(double &median, priority_queue<int>&maxHeap, priority_queue<int,vector<int>,greater<int> > &minHeap,int element){

    switch(signum(minHeap.size() , maxHeap.size())){
        case 0: if (element > median)
            {
                minHeap.push(element);
                median = minHeap.top();
            }
            else
            {
                maxHeap.push(element);
                median = maxHeap.top();
            }    
            break;
        case 1: if(element > median){
                int minTop = minHeap.top();
                minHeap.pop();
                maxHeap.push(minTop);
                minHeap.push(element);
                median = (minHeap.top()+maxHeap.top())/2.0;

                }
                else{
                maxHeap.push(element);
                median = (minHeap.top()+maxHeap.top())/2.0;
                }
            break;
        case -1: if(element > median){
                minHeap.push(element);
                median = (minHeap.top()+maxHeap.top())/2.0;
                }
                else{
                // pahle max se element nikal ke min me push kar do 
                int maxTop = maxHeap.top();
                maxHeap.pop();
                minHeap.push(maxTop);
                maxHeap.push(element);
                // ab dono ka size = size+1 ho gya hoga
                median = (minHeap.top()+maxHeap.top())/2.0;
            }

        break;
    }
}

void callMedian(int &median, priority_queue<int>&maxHeap, priority_queue<int,vector<int>,greater<int> > &minHeap,int element){
    if (minHeap.size() == maxHeap.size())
    {
        if (element > median)
        {
            minHeap.push(element);
            median = minHeap.top();
        }
        else
        {
            maxHeap.push(element);
            median = maxHeap.top();
        }    
    }
    else if (maxHeap.size() > minHeap.size())
    {
        //right me yani minheap me aasani se insert ho jayega
        if(element > median){
            minHeap.push(element);
            median = (minHeap.top()+maxHeap.top())/2;
        }
        else{
            // pahle max se element nikal ke min me push kar do 
            int maxTop = maxHeap.top();
            maxHeap.pop();
            minHeap.push(maxTop);
            maxHeap.push(element);
            // ab dono ka size = size+1 ho gya hoga
            median = (minHeap.top()+maxHeap.top())/2;
        }
    }
    else{
        // min ka size bada h max se:
        if(element > median){
            int minTop = minHeap.top();
            minHeap.pop();
            maxHeap.push(minTop);
            minHeap.push(element);
            median = (minHeap.top()+maxHeap.top())/2;

        }
        else{
            maxHeap.push(element);
            median = (minHeap.top()+maxHeap.top())/2;
        }
    }
    
}


int main()

{
    int arr[6] = {5,7,2,9,3,8};
    int n = 6;
    double median = 0;
    priority_queue<int>maxHeap;
    priority_queue<int,vector<int>,greater<int> > minHeap;
    for (int i = 0; i < n; i++)
    {
        int element = arr[i];
        // callMedian(median,maxHeap,minHeap,element);
        callMedianUsingSwitch(median,maxHeap,minHeap,element);

        cout<<arr[i]<<" -> "<<median<<endl;
    }
    cout<<endl;
    

 return 0;
}