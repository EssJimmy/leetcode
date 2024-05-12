#include <bits/stdc++.h>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums){
    int n = (int) nums.size();

    vector<int> ans(n);
    int fix = 1;
    for(int i = 0; i < n; i++){
        ans[i] = fix;
        fix *= nums[i];
    }

    fix = 1;
    for(int i = n - 1; i > -1; i--){
        ans[i] *= fix;
        fix *= nums[i];
    }

    return ans;
}


int main(void){
    int n;
    
    cin >> n;
    vector<int> arr(n);

    for(int i = 0; i < n; i++)
        cin >> arr[i];

    for(int& i : productExceptSelf(arr))
        cout << i << " ";

    cout << endl;

    return 0;
}