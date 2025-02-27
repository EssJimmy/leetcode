from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        mpp = {}

        for i in range(len(nums)):
            if nums[i] in mpp:
                return [mpp[nums[i]], i]
            
            mpp[target - nums[i]] = i

        return [-1, -1]
