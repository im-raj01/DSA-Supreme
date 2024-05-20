#include<bits/stdc++.h>
using namespace std;
#define ll long long

void reverseString(string &str,int &start,int &end){
    // base case:
    if(start >= end){
        return;
    }
    //1case:
    swap(str[start++],str[end--]);
    return reverseString(str,start,end);
}
int main()
{
 string str;cin>>str;
 int s = 0,e = str.size()-1;
 reverseString(str,s,e);
 cout<<str<<endl;
 return 0;
}