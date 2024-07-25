// Time complexity: O(sort)
// Space complexity: O(n)
class Solution {
 public:
  vector<int> sortJumbled(
    const vector<int>& mapping,
    const vector<int>& nums
  ) {
    vector<int> ans;
    vector<pair<int, int>> A;

    for (int i = 0; i < nums.size(); ++i)
      A.push_back(make_pair(getMapped(nums[i], mapping), nums[i]));

    ranges::sort(A, [](const pair<int, int>& a, const pair<int, int>& b) {
      return a.first < b.first;
    });

    for (const auto& [_, num] : A)
      ans.push_back(num);

    return ans;
  }

 private:
  int getMapped(int num, const vector<int>& mapping) {
    if (num == 0)
      return mapping[0];

    int mapped = 0;
    int multiplier = 1;

    while (num > 0) {
      int digit = num % 10;
      mapped += mapping[digit] * multiplier;
      num /= 10;
      multiplier *= 10;
    }

    return mapped;
  }
};