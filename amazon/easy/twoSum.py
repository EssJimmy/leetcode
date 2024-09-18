class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        mpp = {}

        for i in range(nums):
            if nums[i] in mpp:
                return [i, mpp[nums[i]]]
            
            mpp[target - nums[i]] = i

        return [-1, -1]


def main():
    nums = [2, 7, 11, 15]
    s = Solution()

    print(s.twoSum(nums, 9))


if __name__ == "__main__":
    main()
    