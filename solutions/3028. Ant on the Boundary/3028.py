# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
    def returnToBoundaryCount(self, nums: List[int]) -> int:
        count = 0
        pos = 0

        for num in nums:
            pos += num
            if pos == 0:
                count += 1

        return count