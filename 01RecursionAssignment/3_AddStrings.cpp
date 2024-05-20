#include<bits/stdc++.h>
using namespace std;
#define ll long long
void AddRE(string &num1,int p1,string &num2 , int p2, int carry, string &ans){
        // base case :
        if(p1 < 0 && p2<0){
            if(carry){
                ans.push_back(carry+'0');
                return;
            }
            return;
        }

        // 1 case:
        int d1 = (p1>=0 ? num1[p1]-'0' : '0' - '0');
        int d2 = (p2>=0 ? num2[p2]-'0' : '0' - '0');
        int csum = d1 + d2 + carry;
        int digit = csum % 10;
        carry = csum / 10;
        ans.push_back(digit+'0');

        // re call
        return AddRE(num1,p1-1,num2,p2-1,carry,ans);

}


 string addStrings(string num1, string num2) {
    int p1 = num1.size()-1;
        int p2 = num2.size()-1;
        string ans;
        AddRE(num1,p1,num2,p2,0,ans);
        reverse(ans.begin(),ans.end());
        return ans;
}
int main()
{
    string num1,num2;
    cin>>num1>>num2;
    cout<<addStrings(num1,num2)<<endl;
 return 0;
}