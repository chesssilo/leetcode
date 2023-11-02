# Time complexity: O(logn)
# Space complexity: O(1)
class Solution:
    def firstBadVersion(self, n: int) -> int:
        good = 0
        bad = n

        while bad > good + 1:
            mid = good + ((bad - good) // 2)
            if isBadVersion(mid):
                bad = mid
            else:
                good = mid

        return bad 