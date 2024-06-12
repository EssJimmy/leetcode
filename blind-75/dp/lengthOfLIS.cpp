#include <bits/stdc++.h>

using namespace std;

int lenghtOfLIS(vector<int>& nums){
    const int n = (int) nums.size();
    vector<int> dp(n, 1);

    for(int i = n - 1; i >= 0; i--){
        for(int j = i + 1; j < n; j++){
            if(nums[i] < nums[j]) dp[i] = max(dp[i], 1 + dp[j]);
        }
    }

    return *max_element(dp.begin(), dp.end());
}

int lengthOfLISnlogn(vector<int>& nums){
    vector<int> dp;
    int ans = 0;

    for(auto el : nums){
        if(dp.size() == 0 || dp.back() < el){
            dp.push_back(el);
            ans++;
        }
        else{
            int idx = lower_bound(dp.begin(), dp.end(), el) - dp.begin();
            dp[idx] = el;
        }
    }

    return ans;
}