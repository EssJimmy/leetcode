#include <bits/stdc++.h>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target){
    unordered_map<int, int> mpp;
    int n = (int) nums.size();
    vector<int> ans(2);

    for(int i = 0; i < n; i++){
        int k = target - nums[i];
        if(mpp.find(nums[i]) != mpp.end()){
            ans[0] = mpp[k];
            ans[1] = i;

            return ans;
        }
        mpp[k] = i;
    }

    return ans;
}

int main(void){
    int n, k;

    cin >> n >> k;
    vector<int> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    vector<int> ans = twoSum(arr, k);
    cout << ans[0] << " " << ans[1] << endl;

    return 0;
}