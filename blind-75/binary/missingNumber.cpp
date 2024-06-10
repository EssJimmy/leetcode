#include <bits/stdc++.h>

using namespace std;

int missingNumber(vector<int>& nums){
    int n = (int) nums.size();

    for(int i = 0; i < (int) nums.size(); i++) n ^= i^nums[i];

    return n;
}