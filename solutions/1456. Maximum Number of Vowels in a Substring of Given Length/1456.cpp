// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  int maxVowels(string_view s, int k) {
    int ans = 0;
    int mx = 0;
    string kVowels = "aeiou";

    for (int i = 0; i < s.size(); ++i) {
      if (kVowels.find(s[i]) != string::npos)
        mx += 1;
      if (i >= k && kVowels.find(s[i - k]) != string::npos)
        mx -= 1;
      ans = max(ans, mx);
    }

    return ans;
  }
};