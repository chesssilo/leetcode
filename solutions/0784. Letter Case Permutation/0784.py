# Time complexity: O(2^n)
# Space complexity: O(2^n)
class Solution:
  def letterCasePermutation(self, s: str) -> List[str]:
    def backtrack(path: List[str], i: int) -> None:
      if i == len(s):
        ans.append(''.join(path))
        return
      
      if s[i].isalpha():
        backtrack(path + [s[i].lower()], i + 1)
        backtrack(path + [s[i].upper()], i + 1)
      else:
        backtrack(path + [s[i]], i + 1)

    ans = []
    backtrack([], 0)

    return ans      