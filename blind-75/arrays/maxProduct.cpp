#include <bits/stdc++.h>

using namespace std;

int maxProduct(vector<int>& nums){
    int ans = *max_element(nums.begin(), nums.end());
    int currMax = 1; int currMin = 1;

    for(int i = 0; i < (int) nums.size(); i++){
        if(nums[i] < 0) swap(currMax, currMin);
        
        currMax = max(nums[i], currMax*nums[i]);
        currMin = min(nums[i], currMin*nums[i]);
        
        ans = max(ans, currMin);
    }

    return ans;
}

int main(void){
    int n;

    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    cout << maxProduct(nums) << endl;

    return 0;
}