# Time complexity: O(nlog(logn))
# Space complexity: O(n)
class Solution:
  def countPrimes(self, n: int) -> int:
    if n <= 2:
      return 0
        
    isPrime = [True] * n
    isPrime[0] = False
    isPrime[1] = False
        
    p = 2
    while p * p < n:
      if isPrime[p]:
        for i in range(p * p, n, p):
          isPrime[i] = False
      p += 1
        
    count = 0
    for i in range(2, n):
      if isPrime[i]:
        count += 1
        
    return count       