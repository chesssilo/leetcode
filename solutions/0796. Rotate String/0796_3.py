# Time complexity: O(n)
# Space complexity: O(n)
class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        if len(s) != len(goal): 
            return False
        n = len(s)

        shifts = [1] * (n+1)
        left = -1
        for right in range(n):
            while left >= 0 and goal[left] != goal[right]:
                left -= shifts[left]
            shifts[right + 1] = right - left
            left += 1

        match_len = 0
        for char in s+s:
            while match_len >= 0 and goal[match_len] != char:
                match_len -= shifts[match_len]

            match_len += 1
            if match_len == n:
                return True

        return False  