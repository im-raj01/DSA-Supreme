#include<bits/stdc++.h>
using namespace std;
#define ll long long

int factorial(int n){
    // base case
    if(n==1){
        return n;
    }
    // cout<<n<<endl;
    // int ans = n*factorial(n-1);

    int chotiProblemAns = factorial(n-1);
    int badiProblemAns = n * chotiProblemAns;
    return badiProblemAns;
}
int main()
{
 int n;cin>>n;
 int ans = factorial(n);
 cout<<ans<<endl;
 return 0;
}
