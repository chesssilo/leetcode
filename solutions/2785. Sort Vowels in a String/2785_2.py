# Time complexity: O(n)
# Space complexity: O(n)
class Solution:
  def sortVowels(self, s: str) -> str:
    kVowels = 'AEIOUaeiou'
    count = [0] * 128
    for c in s:
      if c in kVowels:
        count[ord(c)] += 1

    ans = ""
    j = 0
    for i, c in enumerate(s):
      if c not in kVowels:
        ans += s[i]
      else:
        while count[ord(kVowels[j])] == 0:
          j += 1

        ans += kVowels[j]
        count[ord(kVowels[j])] -= 1

    return ans