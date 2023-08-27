# Time complexity: O(nlogk)
# Space complexity: O(n)
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counter = Counter(nums)
        heap = []
    
        for num, freq in counter.items():
            heapq.heappush(heap, (-freq, num))
    
        res = []
        for _ in range(k):
            res.append(heapq.heappop(heap)[1])
    
        return res