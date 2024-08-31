#include<bits/stdc++.h>
using namespace std;
#define ll long long

class node{
    public:
    int data;
    int count;

    node(char d, int c){
        data = d;
        count = c;
    }
};

class compare{
public:
    bool operator()(node a , node b){
        return a.count < b.count;
    }
};
class Solution {
public:

    string reorganizeString(string s) {
        //create mapping:
        int freq[26] ={0};
        for(int i =0;i<s.size();i++){
            char ch = s[i];
            freq[ch-'a']++;
        }
        //maxheap create karo
        priority_queue<node,vector<node>,compare>maxHeap;

        for(int i = 0;i<26;i++){
            if(freq[i] != 0){
                node temp(i+'a',freq[i]);
                maxHeap.push(temp);
            }
        }

        //ans ko store karko 
        string ans = "";
        while(maxHeap.size() > 1){
            node first = maxHeap.top();
            maxHeap.pop();
            node second = maxHeap.top();
            maxHeap.pop();

            ans += first.data;
            ans += second.data;

            first.count--;
            second.count--;
            if(first.count != 0){
                maxHeap.push(first);
            }
            if(second.count != 0){
                maxHeap.push(second);
            }
        }

        if(maxHeap.size() == 1){
            node temp = maxHeap.top();
            maxHeap.pop();
            if(temp.count == 1){
                ans += temp.data;

            }
            else{
                return "";
            }
        }
        return ans;

    }











};

int main()
{

 return 0;
}