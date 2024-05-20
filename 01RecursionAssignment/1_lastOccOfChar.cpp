#include<bits/stdc++.h>
using namespace std;
#define ll long long

void lastOccurLTR(string &str,char ch,int &ans,int index){
    // base case:
    if(index>=str.size()){
        return;
    }
    //ek case solve kar do
    if (str[index] == ch)
    {
        ans = index;
    }
    //rec call 
    return lastOccurLTR(str,ch,ans,++index);
    
}

int main()
{
    string s;
    cin>>s;
    char ch;
    cin>>ch;
    int ans=-1;
    lastOccurLTR(s,ch,ans,0);
    cout<<ans<<endl;

 return 0;
}