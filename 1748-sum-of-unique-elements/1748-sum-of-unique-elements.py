class Solution:
    def sumOfUnique(self, nums: List[int]) -> int:
        nums.sort()
        n = len(nums)
        sum = 0
        for i in range(n):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            if i < n-1 and nums[i] == nums[i+1]:
                continue
            sum = sum + nums[i]
        return sum