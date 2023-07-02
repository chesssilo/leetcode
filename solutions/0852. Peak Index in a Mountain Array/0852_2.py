# Time complexity: O(log⁡n)
# Space complexity: O(1)
class Solution :
    def peakIndexInMountainArray(self, arr: List[int]) -> int:
        start = 0
        end = len(arr)

        while start < end:
            mid = (start + end) // 2
            if arr[mid] < arr[mid + 1]: 
                start = mid + 1
            else:
                end = mid

        return start