// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  int addedInteger(const vector<int>& nums1, const vector<int>& nums2) {
    return *min_element(begin(nums2), end(nums2)) - 
           *min_element(begin(nums1), end(nums1));
  }
};