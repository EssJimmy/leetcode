#include <bits/stdc++.h>

using namespace std;

int maxArea(vector<int>& nums){
    int ans = 0;

    int l = 0, r = (int) nums.size() - 1;
    while(l < r){
        ans = max(min(nums[l], nums[r])*(r-l), ans);
        if(nums[l] > nums[r]) r--;
        else l++;
    }

    return ans;
}