#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
       /* Brute force:
        int maxlen = 0;
        int n = s.size();
        for(int i = 0;i<n;i++){
            int hash[256] = {0};
            for(int j = i;j<n;j++){
               // cout<<"ans"<<endl;
               char ch = s[j];
               if(hash[ch] == 1){
                break;
               }
               int len = j-i+1;
               maxlen = max(len,maxlen);
               hash[ch] = 1;
            }
        }
        return maxlen;*/

        int l = 0,r = 0, maxlen = 0;
        int n = s.size();
        int hash[256];
        for(int i = 0;i<256;i++){
            hash[i]= -1;
        }
        while(r < n){
            int ch = s[r];
            if(hash[ch] != -1){
                if(hash[ch] >= l){
                    l = hash[ch] + 1;
                }
            }
            int len = r-l+1;
            maxlen = max(len,maxlen);
            hash[ch] = r;
            r++;
        }
        return maxlen;

    }
};
int main()
{

 return 0;
}