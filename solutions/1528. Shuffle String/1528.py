# Time complexity: O(n)
# Space complexity: O(n)
class Solution:
  def restoreString(self, s: str, indices: List[int]) -> str:
    ans = [''] * len(s)

    for i, index in enumerate(indices):
      ans[index] = s[i]

    return ''.join(ans)