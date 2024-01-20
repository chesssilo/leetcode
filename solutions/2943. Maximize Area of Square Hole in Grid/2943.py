# Time complexity: O(nlogn)
# Space complexity: O(n)
class Solution:
    def maximizeSquareHoleArea(self, n: int, m: int, hBars: List[int], vBars: List[int]) -> int:
        gap = min(self.max_continuous_gap(hBars), self.max_continuous_gap(vBars))
        return gap * gap

    def max_continuous_gap(self, bars: List[int]) -> int:
        res = 2
        running_gap = 2
        bars.sort()
        for i in range(1, len(bars)):
            running_gap = running_gap + 1 if bars[i] == bars[i - 1] + 1 else 2
            res = max(res, running_gap)
        
        return res