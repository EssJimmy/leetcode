#include <bits/stdc++.h>

using namespace std;

int maxSubArray(vector<int>& nums){
    int ans = INT_MIN;
    int a = 0;
    

    for(int i = 0; i < (int) nums.size(); i++){
        a += nums[i];
        
        if(ans < a) ans = a;
        if(a < 0) a = 0;
    }

    return ans;
}

int main(void){
    int n;

    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    cout << maxSubArray(nums) << endl;

    return 0;
}