# Time complexity: O(nk)
# Space complexity: O(n)
class Solution:
    def maxSumAfterPartitioning(self, arr: List[int], k: int) -> int:
        n = len(arr)
        max_sum = [0] * (n + 1)

        for start in range(n - 1, -1, -1):
            curr_max = 0
            for i in range(start, min(n, start + k)):
                curr_max = max(curr_max, arr[i])
                max_sum[start] = max(max_sum[start], max_sum[i + 1] + curr_max * (i - start + 1))

        return max_sum[0]        