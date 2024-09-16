// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  int findTheLongestSubstring(string_view s) {
    constexpr string_view kVowels = "aeiou";
    int ans = 0;
    int prefix = 0;
    unordered_map<int, int> prefixToIndex{{0, -1}};

    for (int i = 0; i < s.length(); ++i) {
      const int index = kVowels.find(s[i]);
      if (index != -1)
        prefix ^= 1 << index;
      if (!prefixToIndex.contains(prefix))
        prefixToIndex[prefix] = i;
      ans = max(ans, i - prefixToIndex[prefix]);
    }

    return ans;
  }
};