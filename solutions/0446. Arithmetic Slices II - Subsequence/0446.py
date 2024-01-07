# Time complexity: O(n^2)
# Space complexity: O(n^2)
class Solution:
    def numberOfArithmeticSlices(self, nums: List[int]) -> int:
        n = len(nums)
        ans = 0
        dp = [[0] * n for _ in range(n)]
        num_to_indices = {}

        for i in range(n):
            num_to_indices.setdefault(nums[i], []).append(i)

        for i in range(n):
            for j in range(i):
                target = nums[j] * 2 - nums[i]
                if target in num_to_indices:
                    for k in num_to_indices[target]:
                        if k < j:
                            dp[i][j] += (dp[j][k] + 1)

                ans += dp[i][j]

        return ans                        