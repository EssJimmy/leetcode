#include <bits/stdc++.h>

using namespace std;

bool wordBreak(string s, vector<string>& wordDict){
    vector<int> dp(s.length()+1);
    dp[s.length()] = true;

    for(int i = s.length()-1; i > 0; i--){
        for(string w : wordDict) {
            if(i + w.length() <= s.length() && w == s.substr(i, w.length())){
                dp[i] = 1;
            }
            if(dp[i]) break;
        }
    }
    
    return dp[0];
}

int main(void){
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};

    cout << wordBreak(s, wordDict) << endl;

    return 0;
}