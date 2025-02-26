#include <bits/stdc++.h>

using namespace std;

class Solution{
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;

        if(nums.empty()) return ans;
        
        int start = nums[0];
        int *current = &start;

        for(auto i = 1; i < nums.size(); i++) {
            if(*current + 1 == nums[i]) 
                current = &nums[i];
                
            else {
                string temp = to_string(start);
                    
                if(current != &start) 
                    temp += "->" + to_string(*current);
                    
                ans.push_back(temp);
                start = nums[i];
                current = &start;
            }
        }

        string temp = to_string(start);
        if(current != &start) {
            temp += "->" + to_string(*current);
        }
        ans.push_back(temp);

        return ans;
    }
};