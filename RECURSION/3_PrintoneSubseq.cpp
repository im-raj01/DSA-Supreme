#include<bits/stdc++.h>
using namespace std;
#define ll long long

// YAHAH PE RECURSIVE CALL RUK RAHA HAI 
bool printOneSubsequence(int ind,vector<int>&ds,int sum , int target, vector<int>&arr){
    //base case:
    if(ind >= arr.size()){
        if(target == sum){
            //print kar do ds ko
            for (int i = 0; i < ds.size(); i++)
            {
                cout<<ds[i]<<" ";
            }
            
            return true;
        }
        return false;
    }
    //hr index pe :
    ds.push_back(arr[ind]);
    sum += arr[ind];
    cout<<"TAKe call"<<endl;
    if(printOneSubsequence(ind+1,ds,sum,target,arr) == true)return true;
    cout<<"TAKe-NOT call"<<endl;

    ds.pop_back();
    sum -= arr[ind];
    if(printOneSubsequence(ind+1,ds,sum,target,arr) == true)return true;
    return false;
}
int main()
{
    vector<int>arr= {1,2,1
    };
    vector<int>ds;
    int target = 2;
    int sum = 0;
    printOneSubsequence(0,ds,sum,target,arr);
 return 0;
}




















/*-
#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool flag = false;
void printSubsequence(int ind,vector<int>&ds,int sum, int target, vector<int>&arr){
    //base case:
    if(ind >= arr.size()){
        if(target == sum){
            //print kar do:
            flag = true;
            for (int i = 0; i < ds.size(); i++)
            {
                cout<<ds[i]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    if(flag){
        return;
    }
    //hr index pe kya karna h:
    cout<<"take call"<<endl;
    ds.push_back(arr[ind]);
    sum += arr[ind];
    printSubsequence(ind+1,ds,sum,target,arr);
    cout<<"take-NOT call"<<endl;

    ds.pop_back();
    sum -= arr[ind];
    printSubsequence(ind+1,ds,sum,target,arr);
    // cout<<"AFTER NOT TAKE CALL"<<endl;

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
*/