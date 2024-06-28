// Time complexity: O(max(m,n))
// Space complexity: O(m+n)
class Solution {
 public:
  string mergeAlternately(string word1, string word2) {
    const int n = min(word1.length(), word2.length());
    string pref;

    for (int i = 0; i < n; ++i) {
      pref += word1[i];
      pref += word2[i];
    }

    return pref + word1.substr(n) + word2.substr(n);
  }
};