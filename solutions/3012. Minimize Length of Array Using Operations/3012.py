# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
    def minimumArrayLength(self, nums: List[int]) -> int:
        min_num = min(nums)
        if any(num % min_num > 0 for num in nums):
            return 1

        return (nums.count(min_num) + 1) // 2