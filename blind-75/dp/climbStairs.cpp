#include <bits/stdc++.h>

using namespace std;

int climbStairs(int n){
    if(n == 0 || n == 1 || n == 2) return n;

    vector<int> dp(n + 1, -1);
    dp[0] = 1; dp[1] = 1;
    for(int i = 2; i <= n; i++) dp[i] = dp[i - 1] + dp[i - 2];

    return dp[n];
}

int main(void){
    int n;

    cin >> n;
    cout << climbStairs(n) << endl;

    return 0;
}