#include <bits/stdc++.h>

using namespace std;

int findMin(vector<int>& nums){
    int l = 0, r = int(nums.size()) - 1;
    int ans = nums[0];

    while(l <= r){
        if(nums[l] < nums[r]) {
            ans = min(nums[l], ans);
            break;
        }

        int m = (l + r)/2;
        ans = min(nums[m], ans);

        if(nums[m] >= nums[l]){ l = m + 1; }
        else{ r = m - 1; }   
    }

    return ans;
}