# Time complexity: O(n + m)
# Space complexity: O(n)
class Solution:
  def countMatchingSubarrays(self, nums: List[int], pattern: List[int]) -> int:
    numsPattern = []
    for i in range(1, len(nums)):
      numsPattern.append((0 < nums[i] - nums[i - 1]) -(0 > nums[i] - nums[i - 1]))

    return self.rabinKarp(numsPattern, pattern)

  def rabinKarp(self, numsPattern: List[int], pattern: List[int]) -> int:
    p = 31
    kMod = 1_000_000_001
    patternPow = 1
    hT = 0
    hS = 0
    res = 0

    for i in range(len(pattern)):
      hT = (hT * p + (pattern[i] + 1)) % kMod
      patternPow = (patternPow * p) % kMod

    for i in range(len(numsPattern)):
      hS = (hS * p + (numsPattern[i] + 1)) % kMod
      if i >= len(pattern):
        hS = (kMod + hS - patternPow * (numsPattern[i - len(pattern)] + 1) % kMod) % kMod
      if i + 1 >= len(pattern) and hT == hS:
        res += 1

    return res