# Time complexity: O(2^n)
# Space complexity: O(n)
class Solution:
  def maxUniqueSplit(self, s: str) -> int:
    def dfs(start: int, seen: set) -> None:
      nonlocal ans

      if start == len(s):
        ans = max(ans, len(seen))
        return

      for i in range(1, len(s) - start + 1):
        cand = s[start:start + i]
        if cand in seen:
          continue
        seen.add(cand)
        dfs(start + i, seen)
        seen.remove(cand)

    ans = 0
    dfs(0, set())
    return ans