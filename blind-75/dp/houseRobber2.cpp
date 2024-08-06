#include <bits/stdc++.h>

using namespace std;

int rob(vector<int>& nums){
    int rob1 = 0, rob2 = 0;

    for(int i = 0; i < (int) nums.size() - 1; i++) {
        int temp = max(nums[i] + rob1, rob2);
        rob1 = rob2;
        rob2 = temp;
    }

    int m1 = rob2;
    rob1 = 0; rob2 = 0;
    for(int i = 1; i < (int) nums.size(); i++) {
        int temp = max(nums[i] + rob1, rob2);
        rob1 = rob2;
        rob2 = temp;
    }

    return max(nums[0], max(m1, rob2));
}