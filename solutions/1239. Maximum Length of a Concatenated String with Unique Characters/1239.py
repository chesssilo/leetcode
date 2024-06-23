# Time complexity: O(2^n)
# Space complexity: O(n)
class Solution:
  def maxLength(self, arr: List[str]) -> int:
    def get_mask(s: str) -> int:
      mask = 0
      for c in s:
        bit = 1 << (ord(c) - ord('a'))
        if mask & bit:
          return 0
        mask |= bit
      
      return mask

    def dfs(masks: List[int], pos: int, used: int) -> int:
      max_len = bin(used).count('1')
      for i in range(pos, len(masks)):
        if masks[i] & used == 0:
          max_len = max(max_len, dfs(masks, i + 1, used | masks[i]))
      
      return max_len

    masks = [get_mask(s) for s in arr if get_mask(s) > 0]
    return dfs(masks, 0, 0)