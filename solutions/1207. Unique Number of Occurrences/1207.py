# Time complexity: O(n)
# Space complexity: O(n)
class Solution:    
    def uniqueOccurrences(self, arr: List[int]) -> bool:
            count = collections.Counter(arr)
            unique = set()

            for value in count.values():
                if value in unique:
                    return False
                unique.add(value)

            return True