// Time complexity: O(n+m)
// Space complexity: O(1)
class Solution {
 public:
  bool canConstruct(string_view ransomNote, string_view magazine) {
    vector<int> count(26);

    for (const char c : magazine)
      ++count[c - 'a'];

    for (const char c : ransomNote) {
      if (count[c - 'a'] == 0)
        return false;
      --count[c - 'a'];
    }

    return true;
  }
};