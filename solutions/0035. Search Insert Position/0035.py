# Time complexity: O(logn)
# Space complexity: O(1)
class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        start = 0
        end = len(nums)
       

        while start < end:
            mid = start + (end - start) // 2
            if nums[mid] == target:
                return mid
            if nums[mid] > target:
                end = mid 
            if nums[mid] < target:
                start = mid + 1

        return start