# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        frequency = {}

        for c in s:
            frequency[c] = frequency.get(c, 0) + 1
    
        for c in t:
            frequency[c] = frequency.get(c, 0) - 1

        for char, freq in frequency.items():
            if freq < 0:
                return char
    
        return ' '