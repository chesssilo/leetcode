# Time Complexity: O(n)
# Space Complexity: O(n)
class Solution:
  def shortestSubarray(self, nums: List[int], k: int) -> int:
    n = len(nums)
    ans = n + 1
    dq = collections.deque()
    prefix = list(itertools.accumulate(nums, initial=0))

    for i in range(n + 1):
      while dq and prefix[i] - prefix[dq[0]] >= k:
        ans = min(ans, i - dq.popleft())
      while dq and prefix[i] <= prefix[dq[-1]]:
        dq.pop()
      dq.append(i)

    return ans if ans <= n else -1