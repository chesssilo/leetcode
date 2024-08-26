// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  int averageValue(const vector<int>& nums) {
    int count = 0;
    int sum = 0;

    for (const int num : nums)
      if (num % 6 == 0) {
        sum += num;
        ++count;
      }

    return count == 0 ? 0 : sum / count;
  }
};