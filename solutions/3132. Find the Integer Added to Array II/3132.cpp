// Time complexity: O(sort)
// Space complexity: O(sort)
class Solution {
 public:
  int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
    ranges::sort(nums1);
    ranges::sort(nums2);
    int ans = INT_MAX;

    for (int i = 0; i < 3; ++i) {
      int skip = i;
      for (int j = i + 1; skip < 3 && j - skip < nums2.size(); ++j)
        skip += nums2[j - skip] - nums1[j] != nums2[0] - nums1[i];
      if (skip < 3)
        ans = min(ans, nums2[0] - nums1[i]);
    }

    return ans;
  }
};