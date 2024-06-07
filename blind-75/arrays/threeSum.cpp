#include <bits/stdc++.h>

using namespace std;


vector<vector<int>> threeSum(vector<int>& nums){
    sort(nums.begin(), nums.end());
    const int n = (int) nums.size();
    vector<vector<int>> ans;

    for(int i = 0; i < n; i++){
        if(i > 0 && nums[i] == nums[i-1]) continue;
        int l = i + 1, r = n - 1;

        while(l < r){
            int temp = nums[i] + nums[l] + nums[r];
            if(temp > 0) r--;
            else if(temp < 0) l++;
            else {
                vector<int> aux = {nums[i], nums[l], nums[r]};
                ans.push_back(aux);

                l++;
                while(nums[l] == nums[l-1] && l < r) l++;
            };
        }
    }

    return ans;
}