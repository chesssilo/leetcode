// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
 public:
  int duplicateNumbersXOR(const vector<int>& nums) {
    unordered_map<int, int> count;
    int ans = 0;

    for (const int num : nums)
      ++count[num];

    for (const auto& [num, freq] : count)
      if (freq == 2)
        ans ^= num;

    return ans;
  }
};