// # Time complexity: O(2^n)
// Space complexity: O(2^n)
class Solution {
 public:
  vector<string> letterCasePermutation(string s) {
    vector<string>ans;
    backtrack(s, 0, ans);

    return ans;
  }
 private:
  void backtrack(string& s, int i, vector<string>& ans) {
    if (i == s.length()) {
      ans.push_back(s);
      return;
    }
    if (isdigit(s[i])) {
      backtrack(s, i + 1, ans);
      return;
    }

    s[i] = tolower(s[i]);
    backtrack(s, i + 1, ans);
    s[i] = toupper(s[i]);
    backtrack(s, i + 1, ans);
  }
};