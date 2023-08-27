# Time complexity: O(n)
# Space complexity: O(n)
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counts = {}
        freq = [[] for _ in range(len(nums) + 1)]

        for num in nums:
            counts[num] = counts.get(num, 0) + 1
        for num, count in counts.items():
            freq[count].append(num)

        res = []

        for i in range(len(freq) - 1, 0, - 1):
            for num in freq[i]:
                res.append(num)
                if len(res) == k:
                    return res
            
        return res        