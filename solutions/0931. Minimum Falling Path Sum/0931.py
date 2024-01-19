# Time complexity: O(n^2)
# Space complexity: O(1)
class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        n = len(matrix)
        for i in range(1, n):
            for j in range(n):
                minVal = math.inf
                for k in range(max(0, j - 1), min(n, j + 2)):
                    minVal = min(minVal, matrix[i - 1][k])
                matrix[i][j] += minVal

        return min(matrix[-1])  