class Solution:
    def twoSum(self, nums: list, target: int) -> list:
        for i in range(len(nums)):
            for j in range(i + 1, len(nums)):
                if nums[j] == target - nums[i]:
                    return [i, j]

nums = [2,3,11,3,12,7]
target = 6

s = Solution()
print(s.twoSum(nums, target))   