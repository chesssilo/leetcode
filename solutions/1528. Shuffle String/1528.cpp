// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
 public:
  string restoreString(string_view s, const vector<int>& indices) {
    string ans(s.length(), '.');

    for (int i = 0; i < indices.size(); ++i)
      ans[indices[i]] = s[i];

    return ans;
  }
};