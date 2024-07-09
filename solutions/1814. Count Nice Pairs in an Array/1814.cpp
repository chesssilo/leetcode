// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
 public:
  int countNicePairs(const vector<int>& nums) {
    constexpr int kMod = 1'000'000'007;
    long ans = 0;
    unordered_map<int, int> count;

    for (const int num : nums)
      ++count[num - rev(num)];

    for (const auto& [_, freq] : count) {
      ans += freq * (freq - 1) / 2;
      ans %= kMod;
    }

    return ans;
  }
 private:
  int rev(int n) {
    int x = 0;

    while (n) {
      x = x * 10 + n % 10;
      n /= 10;
    }

    return x;
  }
};