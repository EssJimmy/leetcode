#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    vector<int> topKFrequent(vector<int>& nums, int k){
        map<int, int> mpp;
        vector<int> ans(k);

        for(auto& i : nums)
            mpp[i]++;

        for(auto it = mpp.begin(); it != mpp.end(); it++)
            cout << it->first << " " << it->second << " ";

        cout << endl;

        for(auto i = 0; i < k; i++){
            auto pr = max_element(begin(mpp), end(mpp), [](const pair<int, int> p1, const pair<int, int> p2) {
                return p1.second < p2.second;
            });

            ans[i] = pr->first;
            mpp.erase(pr->first);
        }

        return ans;
    }
};

int main(){
    int n, k;

    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++)
        cin >> nums[i];

    cin >> k;
    auto s = Solution();
    for(auto& i : s.topKFrequent(nums, k))
        cout << i << " ";

    cout << endl;
    return 0;
}