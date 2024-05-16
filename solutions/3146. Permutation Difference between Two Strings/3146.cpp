// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  int findPermutationDifference(string_view s, string_view t) {
    int ans = 0;
    int indices[26] = {};

    for (int i = 0; i < t.length(); ++i)
      indices[t[i] - 'a'] = i;

    for (int i = 0; i < s.length(); ++i)
      ans += abs(i - indices[s[i] - 'a']);

    return ans;    
  }
};
