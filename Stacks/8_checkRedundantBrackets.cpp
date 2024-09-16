#include<bits/stdc++.h>
using namespace std;
#define ll long long

bool checkRedundantBrackets(string &str){
     stack<char>st;
     for(auto ch: str){
        if(ch == ')'){
            char top = st.top();
            st.pop();

            bool flag = true;
            while (!st.empty() and top != '(')
            {
                //check for operators in operation:
                if(top == '+' || top == '-' || top == '*' || top == '/'){
                    flag = false;
                }
                top = st.top();
                st.pop();
            }
            if(flag == true){
                return true;
            }
        }
        else{
            st.push(ch);
        }
     }
     return false;
}
int main()
{
    string str = "(a+b)";
    cout<<checkRedundantBrackets(str);
    return 0;
}