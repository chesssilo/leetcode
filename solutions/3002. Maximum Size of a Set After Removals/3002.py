# Time complexity: O(n)
# Space complexity: O(n)
class Solution:
    def maximumSetSize(self, nums1: List[int], nums2: List[int]) -> int:
        set1 = set(nums1)
        set2 = set(nums2)
        common = set1.intersection(set2)

        n = len(nums1)
        n1 = len(set1)
        n2 = len(set2)
        nc = len(common)
        max_unique_nums1 = min(n1 - nc, n // 2)
        max_unique_nums2 = min(n2 - nc, n // 2)
        
        return min(n, max_unique_nums1 + max_unique_nums2 + nc)