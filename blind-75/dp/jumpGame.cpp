#include <bits/stdc++.h>

using namespace std;

bool canJump(vector<int>& nums){
    int ptr = (int) nums.size() - 1;

    for(int i = (int) nums.size()-1; i >= 0; i--){
        if(i + nums[i] >= ptr) ptr = i;
    }

    return ptr == 0;
}