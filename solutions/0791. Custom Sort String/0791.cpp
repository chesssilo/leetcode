// Time complexity: O(∣order∣+∣s∣)
// Space complexity: O(26)
class Solution {
public:
  string customSortString(string_view order, string_view s) {
    string ans;
    vector<int> count(128);

    for (const char c : s)
      ++count[c];

    for (const char c : order)
      while (count[c]-- > 0)
        ans += c;

    for (char c = 'a'; c <= 'z'; ++c)
      while (count[c]-- > 0)
        ans += c;

    return ans;
  }
};