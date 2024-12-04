// Time complexity: O(nm)
// Space complexity: O(1)
class Solution {
 public:
  string firstPalindrome(const vector<string>& words) {
    for (const string& word : words)
      if (isPalindrome(word))
        return word;
    return "";
  }

 private:
  bool isPalindrome(const string& s) {
    int i = 0;
    int j = s.length() - 1;
    while (i < j)
      if (s[i++] != s[j--])
        return false;
    return true;
  }
};