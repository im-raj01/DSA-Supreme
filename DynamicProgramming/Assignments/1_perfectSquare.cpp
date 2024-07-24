#include <bits/stdc++.h>
using namespace std;
#define ll long long
// https://leetcode.com/problems/perfect-squares/description/

int Solver(int n)
{
    // base case:
    cout<<"call for number "<<n<<endl;
    if (n == 0)
    {
        return 0;
    }
    if(n < 0){
        return 0;
    }


    int ans = INT_MAX;
    // 1 case:
    int i = 1;
    int end = sqrt(n);
    cout<<" here end is :"<<end<<endl;
    while (i <= end)
    {
        int perfectSquare = i * i;
        int numberOfPerfectSquare = 1 + Solver(n - perfectSquare);
        cout<<" ans is :"<<ans<<endl;
        cout<<" no of perfect square is :"<<numberOfPerfectSquare<<endl;
        ans = min(ans, numberOfPerfectSquare);
        i++;
    }
    return ans;
}


int numSquares(int n)
{
    return Solver(n);
}
int main()
{
    int n = 5;
    cout<<numSquares(n)<<endl;

    return 0;
}