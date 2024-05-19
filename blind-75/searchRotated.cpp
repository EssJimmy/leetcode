#include <bits/stdc++.h>

using namespace std;

int search(vector<int>& nums, int target){
    int l = 0, r = int(nums.size()) - 1;
    
    while(l <= r){
        int m = (l + r)/2;

        if(nums[m] == target) return m;

        if(nums[l] <= nums[m]){
            if(target > nums[m] || target < nums[l]) l = m + 1;
            else r = m - 1;
        }
        else{
            if(target < nums[m] || target > nums[r]) r = m - 1;
            else l = m + 1;
        }
    }

    return -1;
}

int main(void){
    int n, target;

    cin >> n >> target;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    cout << search(arr, target) << endl;
    return 0;
}