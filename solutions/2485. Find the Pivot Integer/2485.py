# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
    def pivotInteger(self, n: int) -> int:
        for i in range(0, n + 1):
            if (1 + i) * i == (i + n) * (n - i + 1):
                return i
        return -1