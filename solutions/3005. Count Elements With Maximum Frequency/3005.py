# Time complexity: O(n)
# Space complexity: O(n)
class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        count = Counter(nums)
        max_count = max(count.values())
        ans = sum(i for i in count.values() if i == max_count)
        
        return ans