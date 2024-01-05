# Time complexity: O(nlogn)
# Space complexity: O(n)
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        tails = []

        for num in nums:
            if not tails or num > tails[-1]:
                tails.append(num)
            else:
                tails[bisect.bisect_left(tails, num)] = num

        return len(tails)