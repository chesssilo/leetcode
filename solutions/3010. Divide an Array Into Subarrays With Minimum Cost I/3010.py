# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
    def minimumCost(self, nums: List[int]) -> int:
        k_max = 50
        min1 = k_max
        min2 = k_max

        for i in range(1, len(nums)):
            if nums[i] < min1:
                min2 = min1
                min1 = nums[i]
            elif nums[i] < min2:
                min2 = nums[i]

        return nums[0] + min1 + min2  