#include <bits/stdc++.h>

using namespace std;

int dfs(unordered_map<int, int> dp, string s, int i){
    if(dp.find(i) != dp.end()) return dp[i];
    if(s[i] == '0') return 0;

    int ans = dfs(dp, s, i + 1);
    if(i+1 < s.length()  && (s[i] == '1' || 
        (s[i] == '2' && (s[i+1] >= '0' || s[i+1] <= '6')))) {
        
        ans += dfs(dp, s, i + 2);
    }

    dp[i] = ans;
    return ans;
}

    int numDecodings(string s){
        unordered_map<int, int> dp;

        dp[s.length()] = 1;
        for(int i = s.length() - 1; i >= 0; i--){
            if(s[i] == '0') dp[i] = 0;
            else 
                dp[i] = dp[i + 1];
            
            if(i+1 < s.length()  && (s[i] == '1' || 
            (s[i] == '2' && (s[i+1] >= '0' || s[i+1] <= '6')))) {
                dp[i] = dp[i + 2];
            }
        }

        return dp[0];
    }