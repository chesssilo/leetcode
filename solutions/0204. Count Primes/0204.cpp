// Time complexity: O(nlog(logn))
// Space complexity: O(n)
class Solution {
 public:
  int countPrimes(int n) {
    if ( n <= 2)
      return 0;

    vector<bool> isPrime(n, true);
    isPrime[0] = false;
    isPrime[1] = false;

    for (int p = 2; p * p < n; ++p)
      if (isPrime[p])
        for (int i = p * p; i < n; i += p)
          isPrime[i] = false;

    int count = 0;
    for (int i = 2; i < n; ++i)
      if (isPrime[i])
        count++;

    return count;
  }
};