// Time complexity: O(n^2)
// Space complexity: O(n)
class Solution {
 public:
  int minimumSubstringsInPartition(string_view s) {
    const int n = s.length();
    vector<int> dp(n, n);

    for (int i = 0; i < n; ++i) {
      vector<int> count(26);
      for (int j = i; j >= 0; --j) {
        ++count[s[j] - 'a'];
        if (isBalanced(count))
          dp[i] = j > 0 ? min(dp[i], 1 + dp[j - 1]) : 1;
      }
    }

    return dp.back();
  }
 private:
  static constexpr int kMax = 1001;

  bool isBalanced(const vector<int>& count) {
    int minFreq = kMax;
    int maxFreq = 0;
    for (const int freq : count)
      if (freq > 0) {
        minFreq = min(minFreq, freq);
        maxFreq = max(maxFreq, freq);
      }

    return minFreq == maxFreq;
  }
};