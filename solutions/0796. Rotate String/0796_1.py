# Time complexity: O(n^2)
# Space complexity: O(1)
class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        if len(s) != len(goal):
            return False

        for shift in range(len(s)):
            if all(s[(shift + i) % len(s)] == goal[i] for i in range(len(s))):
                return True
        return False    