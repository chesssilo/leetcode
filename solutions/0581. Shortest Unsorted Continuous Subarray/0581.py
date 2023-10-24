# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        maxi = nums[0]
        last = -1
        
        for i in range(len(nums)):
            maxi = max(maxi, nums[i])
            if nums[i] < maxi:
                last = i
        
        if last == -1:
            return 0
        
        mini = nums[-1]
        first = -1
        for i in range(len(nums)-1, -1, -1):
            mini = min(mini, nums[i])
            if nums[i] > mini:
                first = i
        
        return last - first + 1