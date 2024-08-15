#include <bits/stdc++.h>

using namespace std;

/*O(nlogn) solution but we need a better one
    int longestConsecutive(vector<int>& nums){
        sort(nums.begin(), nums.end());

        int maxVal = 0; int temp = 0;
        for(int i = 1; i < (int) nums.size(); i++){
            if(nums[i] == nums[i-1]+1) ++temp;
            else {
                maxVal = max(maxVal, temp);
                temp = 0;
            }
        }

        return maxVal;
    }
*/

class Solution {
public:
    int longestConsecutive(vector<int>& nums){
        
    }    
};