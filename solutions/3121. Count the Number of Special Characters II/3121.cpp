// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  int numberOfSpecialChars(string_view word) {
    bool lowercase[26] = {false};
    bool uppercase[26] = {false};
    int ans = 0;
    
    for (const char c : word)
      if (islower(c))
        lowercase[c - 'a'] = !uppercase[c - 'a'];
      else
        uppercase[c - 'A'] = true;
        
    for (int i = 0; i < 26; ++i)
      if (lowercase[i] && uppercase[i])
        ++ans;
    
    return ans;
  }
};