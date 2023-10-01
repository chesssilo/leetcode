# Time complexity: O(n)
# Space complexity: O(n)
class Solution:
    def reverseWords(self, s: str) -> str:
        return " ".join([word[::-1] for word in s.split()])             