// Time complexity: O(n+m)
// Space complexity: O(1)
class Solution {
 public:
  int getCommon(const vector<int>& nums1, const vector<int>& nums2) {
    int i = 0;
    int j = 0;

    while (i < nums1.size() && j < nums2.size()) {
      if (nums1[i] == nums2[j])
        return nums1[i];
      if (nums1[i] < nums2[j])
        ++i;
      else 
        ++j;        
    }

    return -1;
  }
};