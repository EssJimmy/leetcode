#include <bits/stdc++.h>

using namespace std;

// for some goddamn reason, o(nlogn) is better than o(n)
class Solution{
public:
    int longestConsecutive(vector<int>& nums){
        set<int> s;

        for(auto i = 0; i < nums.size(); i++) 
            s.insert(nums[i]);
        
        int maxVal = 0, temp = 1;
        for(auto it = s.begin(); it != s.end(); ++it) {
            if(s.contains(*it+1)) ++temp;
            else {
                maxVal = max(maxVal, temp);
                temp = 1;
            }
        }

        if(nums.size() != 0)
            maxVal = max(maxVal, temp);

        return maxVal;
    }
};

//O(n) solution
/*class Solution {
public:
    int longestConsecutive(vector<int>& nums){
        unordered_set<int> set;
        int maxVal = 0;

        for(size_t i = 0; i < nums.size(); i++) 
            set.insert(nums[i]);
        
        for(size_t i = 0; i < nums.size(); i++) {
            if(!set.contains(nums[i] - 1)){
                int temp = 0;
                while(set.contains(nums[i] + temp)) ++temp;

                maxVal = max(maxVal, temp);
            }
            
        }

        return maxVal;
    }    
};*/