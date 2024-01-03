# Time complexity: O(mn)
# Space complexity: O(1)
class Solution:
    def numberOfBeams(self, bank: List[str]) -> int:
        ans = 0
        prev = 0

        for string in bank:
            count = string.count('1')
            if count != 0:
                ans += (count * prev)
                prev = count

        return ans 