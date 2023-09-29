# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
    def isMonotonic(self, nums: List[int]) -> bool:
        increasing = True
        decreasing = True
    
        for i in range(1, len(nums)):
            increasing &= nums[i] >= nums[i - 1]
            decreasing &= nums[i] <= nums[i - 1]

        return increasing or decreasing