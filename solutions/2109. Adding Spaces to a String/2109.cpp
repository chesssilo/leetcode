// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
 public:
  string addSpaces(const string& s, const vector<int>& spaces) {
    string ans;
    ans.reserve(s.size() + spaces.size());
    size_t j = 0;

    for (size_t i = 0; i < s.size(); ++i) {
      if (j < spaces.size() && i == spaces[j]) {
        ans.push_back(' ');
        ++j;
      }
      ans.push_back(s[i]);
    }

    return ans;
  }
};