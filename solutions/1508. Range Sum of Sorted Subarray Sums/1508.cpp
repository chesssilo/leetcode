// Time complexity: O(nlog(S))
// Space complexity: O(1)
class Solution {
 public:
  int rangeSum(const vector<int>& nums, int n, int left, int right) {
    constexpr int kMod = 1'000'000'007;

    auto subarraysAndSumNoGreaterThan = [&](int m) -> pair<int, long> {
      int count = 0;
      long total = 0;
      int sum = 0;
      int window = 0;

      for (int i = 0, j = 0; j < n; ++j) {
        sum += nums[j] * (j - i + 1);
        window += nums[j]; 
        while (window > m) {
          sum -= window;
          window -= nums[i++];
        }
        count += j - i + 1;
        total += sum;
      }

      return {count, total};
    };

    const int L = ranges::min(nums);
    const int R = accumulate(nums.begin(), nums.end(), 0);

    auto firstKSubarraysSum = [&](int k) -> long {
      int l = L;
      int r = R;

      while (l < r) {
        const int m = l + (r - l) / 2;
        if (subarraysAndSumNoGreaterThan(m).first < k)
          l = m + 1;
        else
          r = m;
      }

      const auto& [count, total] = subarraysAndSumNoGreaterThan(l);
      return total - l * (count - k);
    };

    return (firstKSubarraysSum(right) - firstKSubarraysSum(left - 1)) % kMod;
  }
};