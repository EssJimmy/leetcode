def lis(nums):
    l = [1]*len(nums)

    for i in range(1, len(l)):
        subproblems = [l[k] for k in range(i) if nums[k] < nums[i]]
        l[i] = 1 + max(subproblems, default=0)

    return max(l, default=0)


nums = [5, 2, 8, 6, 3, 6, 9, 5]
print(lis(nums))