# Time complexity: O(n)
# Space complexity: O(n)
class Solution:
    def sortArrayByParity(self, nums: List[int]) -> List[int]:
        ans = []

        for i in nums:
            if (i % 2 == 0):
                ans.append(i) 

        for i in nums:
            if i % 2 != 0:
                ans.append(i)

        return ans 