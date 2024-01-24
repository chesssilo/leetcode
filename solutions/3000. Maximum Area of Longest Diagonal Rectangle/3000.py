# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
    def areaOfMaxDiagonal(self, dimensions: List[List[int]]) -> int:
        return max((v[0] * v[0] + v[1] * v[1], v[0] * v[1]) for v in dimensions)[1]    