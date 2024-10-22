#include <iostream>
#include <vector>
using namespace std;

// Recursive function to count the number of ways to make sum x
int countWays(int x, int n, const vector<int>& coins) {
    // Base cases
    if (x == 0) return 1; // There's one way to make sum 0 (by choosing no coins)
    if (x < 0 || n == 0) return 0; // If sum is negative or no coins left, no solution

    // Recursive calls:
    // 1. Include the current coin and subtract its value from the sum (x - coins[n-1])
    // 2. Exclude the current coin and check with the remaining coins (n-1)
    return countWays(x - coins[n - 1], n, coins) + countWays(x, n - 1, coins);
}

int main() {
    int n, x;
    cin >> n >> x; // Input number of coins and the desired sum

    vector<int> coins(n); // Array to store coin denominations
    for (int i = 0; i < n; i++) {
        cin >> coins[i]; // Input each coin value
    }

    // Call the recursive function and print the result
    cout << countWays(x, n, coins) << endl;

    return 0;
}
