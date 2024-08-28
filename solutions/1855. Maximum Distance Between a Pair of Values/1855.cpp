// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  int maxDistance(const vector<int>& nums1, const vector<int>& nums2) {
    int i = 0;
    int j = 0;

    for (; i < nums1.size() && j < nums2.size(); ++j)
      if (nums1[i] > nums2[j])
        ++i;

    return i == j ? 0 : j - i - 1;
  }
};