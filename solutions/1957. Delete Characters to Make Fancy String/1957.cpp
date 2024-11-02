// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
 public:
  string makeFancyString(string_view s) {
    string ans;

    for (const char c : s)
      if (ans.length() < 2 || ans.back() != c || ans[ans.length() - 2] != c)
        ans.push_back(c);

    return ans;
  }
};