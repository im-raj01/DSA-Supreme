#include<bits/stdc++.h>
using namespace std;
#define ll long long

void printSubsequence(int ind,vector<int>&ds,int sum, int target, vector<int>&arr){
    //base case:
    if(ind >= arr.size()){
        if(target == sum){
            //print kar do:
            for (int i = 0; i < ds.size(); i++)
            {
                cout<<ds[i]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    //hr index pe kya karna h:
    ds.push_back(arr[ind]);
    sum += arr[ind];
    printSubsequence(ind+1,ds,sum,target,arr);
    ds.pop_back();
    sum -= arr[ind];
    printSubsequence(ind+1,ds,sum,target,arr);

}
int main()
{
    vector<int>arr= {1,2,1
    };
    vector<int>ds;
    int target = 2;
    int sum = 0;
    printSubsequence(0,ds,sum,target,arr);

 return 0;
}