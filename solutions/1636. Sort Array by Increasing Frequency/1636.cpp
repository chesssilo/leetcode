// Time complexity: O(sort)
// Space complexity: O(n)
class Solution {
 public:
  vector<int> frequencySort(vector<int> nums) {
    unordered_map<int, int> freq;

    for (const int num : nums)
      ++freq[num];

    ranges::sort(nums.begin(), nums.end(), [&](int a, int b) {
      if (freq[a] == freq[b])
        return a > b;
      return freq[a] < freq[b];
    });

    return nums;
  }
};