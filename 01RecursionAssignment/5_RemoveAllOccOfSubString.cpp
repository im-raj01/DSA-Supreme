#include<bits/stdc++.h>
using namespace std;
#define ll long long

string removeOccurrences(string s, string part) {
        while(s.length() != 0 && s.find(part) < s.size()){
            s.erase(s.find(part),part.length());
        }
        return s;
}


int main()
{

 return 0;
}