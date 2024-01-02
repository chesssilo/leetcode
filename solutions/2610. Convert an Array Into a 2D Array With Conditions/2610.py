# Time complexity: O(n)
# Space complexity: O(n)
class Solution:
    def findMatrix(self, nums: List[int]) -> List[List[int]]:
        ans = []
        freq = [0]*(len(nums)+1)

        for num in nums:
            freq[num] += 1
            if freq[num] > len(ans):
                ans.append([])
            ans[freq[num] - 1].append(num)

        return ans