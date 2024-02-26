// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
  bool isPossibleToSplit(const vector<int>& nums) {
    vector<int> count(101);

    for (const int num : nums) {
      ++count[num];
      if (count[num] > 2)
        return false;
    }

    return true;
  }
};