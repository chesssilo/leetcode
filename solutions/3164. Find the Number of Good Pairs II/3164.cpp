// Time complexity: O(n*sqrt(m))
// Space complexity: O(n*sqrt(m))
class Solution {
 public:
  long long numberOfPairs(const vector<int>& nums1, 
                          const vector<int>& nums2, int k) {
    unordered_map<int, int> count;
    long long ans = 0;

    for (const int num : nums1)
      for (int i = 1; i * i <= num; ++i)
        if(i * i == num) {
          ++count[i];
        } else if (num % i == 0) {
          ++count[i];
          ++count[num / i];
        }

    for (int num : nums2) {
      num *= k;
      if (count[num] > 0)
        ans += count[num];
    }

    return ans;
  }
};