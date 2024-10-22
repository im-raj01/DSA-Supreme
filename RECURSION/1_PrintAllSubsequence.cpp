#include<bits/stdc++.h>
using namespace std;
#define ll long long

void printAllSubsequence(vector<int>&arr,int ind, vector<int>&ds){
    //base case:
    if(ind >= arr.size()){
        //print kar do ds ko: 
        for(int i = 0;i<ds.size();i++){
            cout<<ds[i]<<" ";
        }
        cout<<endl;
        return;
    }
    //har index pe 
    ds.push_back(arr[ind]);
    printAllSubsequence(arr,ind+1,ds);
    ds.pop_back();
    printAllSubsequence(arr,ind+1,ds);
}
int main()
{
    vector<int>arr = {3,1,2};
    vector<int>ds;
    printAllSubsequence(arr,0,ds);

 return 0;
}