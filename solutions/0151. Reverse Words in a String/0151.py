# Time complexity: O(n)
# Space complexity: O(n)
class Solution:
    def reverseWords(self, s: str) -> str:
        return ' '.join(reversed(s.split()))     