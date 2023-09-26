# Time complexity: O(n)
# Space complexity: O(1)
class Solution:
    def findTheDifference(self, s: str, t: str) -> str:
        return chr(sum(ord(char) for char in t) - sum(ord(char) for char in s))