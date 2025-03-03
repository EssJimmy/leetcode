from typing import List

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        a = 1
        p = (a*n for n in nums)
        
        ans = []
        for i in nums:
            ans.append(p/i)

        return ans