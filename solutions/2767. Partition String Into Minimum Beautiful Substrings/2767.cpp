// Time complexity: O(n^2)
// Space complexity: O(n)
class Solution {
 public:
  int minimumBeautifulSubstrings(string_view s) {
    const int n = s.length();
    vector<int> dp(n + 1, n + 1);
    dp[0] = 0;

    for (int i = 1; i <= n; ++i) {
      if (s[i - 1] == '0')
        continue;
      int num = 0;
      for (int j = i; j <= n; ++j) {
        num = (num << 1) + s[j - 1] - '0';
        if (isPowerOfFive(num))
          dp[j] = min(dp[j], dp[i - 1] + 1);
      }
    }

    return dp[n] == n + 1 ? -1: dp[n];
  }

 private:
  bool isPowerOfFive(int num) {
    while (num % 5 == 0)
      num /= 5;

    return num == 1;
  }
};