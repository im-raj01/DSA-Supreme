#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool isPalindrome(string &str,int start,int end){
    // base case:
    if(start >= end){
        return true;
    }
    //1 case:
    if(str[start++] != str[end--]){
        return false;
    }
    return isPalindrome(str,start,end);

}
int main()
{
    string str;
    cin>>str;
    int e = str.size()-1;
    cout<<isPalindrome(str,0,e);

 return 0;
}