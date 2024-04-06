// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  bool isAnagram(string_view s, string_view t) {
    if (s.length() != t.length())
      return false;

    vector<int> count(26);

    for (const char c : s)
      ++count[c - 'a'];

    for (const char c : t) {
      if (count[c - 'a'] == 0)
        return false;
      --count[c - 'a'];
    }

    return true;    
  }
};