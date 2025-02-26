class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        ans = 0
        l = 0

        for i in range(1, len(prices)):
            if(prices[l] < prices[i]):
                ans = max(ans, prices[i] - prices[l])
            else:
                l = i

        return ans
    