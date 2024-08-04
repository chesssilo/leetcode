// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
 public:
  bool canBeEqual(const vector<int>& target, vector<int>& arr) {
    return unordered_multiset<int>(arr.begin(), arr.end()) ==
           unordered_multiset<int>(target.begin(), target.end());
  }
};