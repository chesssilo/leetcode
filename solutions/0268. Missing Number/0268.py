# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
    def missingNumber(self, nums: List[int]) -> int:
        ans = len(nums)

        for i, num in enumerate(nums):
            ans ^= i ^ num

        return ans