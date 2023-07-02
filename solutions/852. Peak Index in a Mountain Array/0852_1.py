# Time complexity: O(⁡n)
# Space complexity: O(1)
class Solution: 
    def peakIndexInMountainArray(self, arr: List[int]) -> int:
        i = 0
        while arr[i] < arr[i + 1]:
            i += 1

        return i