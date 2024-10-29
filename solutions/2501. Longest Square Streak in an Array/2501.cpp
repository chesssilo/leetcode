// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
 public:
  int longestSquareStreak(const vector<int>& nums) {
    int ans = 0;
    unordered_set<int> uniqueNums(nums.begin(), nums.end());

    for (const int num : nums) {
      int currStreak = 0;
      long curr = num;

      while (uniqueNums.find((int)curr) != uniqueNums.end()) {
        ++currStreak;
        if (curr * curr > 100'000)
          break;
        curr *= curr;
      }
      ans = max(ans, currStreak);
    }

    return ans < 2 ? -1 : ans;
  }
};