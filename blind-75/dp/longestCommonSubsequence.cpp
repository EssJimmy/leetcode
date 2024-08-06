#include <bits/stdc++.h>

using namespace std;

int longestCommonSubsequence(string text1, string text2){
    vector<vector<int>> dp(text1.length()+1, vector<int>(text2.length()+1));

    for(int i = int(text1.length())-1; i >= 0; i--){
        for(int j = int(text2.length())-1; j >= 0; j--){
            if(text1[i] == text2[j]){ 
                dp[i][j] = dp[i+1][j+1] + 1;
            } else { 
                dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
            }
        }
    }

    return dp[0][0];
}