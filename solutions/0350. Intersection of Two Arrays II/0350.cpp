// Time complexity: O(m+n)
// Space complexity: O(min(m,n))
class Solution {
 public:
  vector<int> intersect(const vector<int>& nums1, const vector<int>& nums2) {
    if (nums1.size() > nums2.size())
      return intersect(nums2, nums1);

    vector<int> ans;
    unordered_map<int, int> count;

    for (const int num : nums1)
      ++count[num];

    for (const int num : nums2)
      if (count[num] > 0) {
        ans.push_back(num);
        --count[num];
      }

    return ans;
  }
};