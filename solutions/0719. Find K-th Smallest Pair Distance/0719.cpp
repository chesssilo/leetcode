// Time complexity: O(sort)+O(nlog(max(nums)−min(nums)))
// Space complexity: O(sort)
class Solution {
 public:
  int smallestDistancePair(vector<int>& nums, int k) {
    ranges::sort(nums);

    int l = 0;
    int r = nums.back() - nums.front();

    while (l < r) {
      const int m = l + (r - l) / 2;
      if (numPairDistancesNoGreaterThan(nums, m) >= k)
        r = m;
      else
        l = m + 1;
    }

    return l;
  }

 private:
  int numPairDistancesNoGreaterThan(const vector<int>& nums, int m) {
    int count = 0;
    int j = 1;

    for (int i = 0; i < nums.size(); ++i) {
      while (j < nums.size() && nums[j] <= nums[i] + m)
        ++j;
      count += j - i - 1;
    }

    return count;
  }
};