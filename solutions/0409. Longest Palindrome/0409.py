# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
    def longestPalindrome(self, s: str) -> int:
        freq = {}
        for char in s:
            freq[char] = freq.get(char, 0) + 1

        length = 0
        odd_count = False
        for count in freq.values():
            if count % 2 == 0:
                length += count
            else:
                length += count - 1
                odd_count = True
        
        if odd_count:
            length += 1
        
        return length