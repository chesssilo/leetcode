# Time complexity: O(n + m)
# Space complexity: O(1)
class Solution:
    def getLastMoment(self, n: int, left: List[int], right: List[int]) -> int:
        ans = 0

        for num in left:
            ans = max(ans, num)

        for num in right:
            ans = max(ans, n - num)

        return ans