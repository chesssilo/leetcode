// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
  bool isPalindrome(string s) {
    int l = 0;
    int r = s.length() - 1;

    while (l < r) {
      while (l < r && !isAlphaNum(s[l]))
        ++l;
      while (l < r && !isAlphaNum(s[r]))
        --r;
      if (toLower(s[l]) != toLower(s[r]))
        return false;
      ++l;
      --r;
    }
    return true;
  }

private: 
    bool isAlphaNum(char c) {
        return ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z') || ('0' <= c && c <= '9');
    }

    char toLower(char c) {
        if ('A' <= c && c <= 'Z') {
            return char(c - 'A' + 'a');
        } else {
            return c;
        }
    }
};