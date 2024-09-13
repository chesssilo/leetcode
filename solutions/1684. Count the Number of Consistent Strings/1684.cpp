// Time complexity: O(m+nk)
// Space complexity: O(1)
class Solution {
 public:
  int countConsistentStrings(string_view allowed, const vector<string>& words) {
    vector<bool> isAllowed(26, false);

    for (int i = 0; i < allowed.length(); ++i)
      isAllowed[allowed[i] - 'a'] = true;

    int ans = 0;

    for (const string_view word : words) {
      bool isConsistent = true;
      for (int i = 0; i < word.length(); ++i)
        if (!isAllowed[word[i] - 'a']) {
          isConsistent = false;
          break;
        }

      if (isConsistent)
        ++ans;
    }

    return ans;
  }
};