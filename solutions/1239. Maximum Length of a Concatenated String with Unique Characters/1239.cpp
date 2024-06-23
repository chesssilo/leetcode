// Time complexity: O(2^n)
// Space complexity: O(n)
class Solution {
 public:
  int maxLength(const vector<string>& arr) {
    vector<bitset<26>> masks;

    for (string_view s : arr) {
      const bitset<26> mask = getMask(s);
      if (mask.count() == s.length())
        masks.push_back(mask);
    }

    return dfs(masks, 0, bitset<26>());
  }
 private:
  int dfs(const vector<bitset<26>>& masks, const int s, 
          const bitset<26> used) {
    int res = used.count();
    for (int i = s; i < masks.size(); ++i)
      if (!(used & masks[i]).any())
        res = max(res, dfs(masks, i + 1, used | masks[i]));

    return res;        
  }

  bitset<26> getMask(string_view s) {
    bitset<26> mask;
    for (const char c : s)
      mask.set(c - 'a');

    return mask;    
  } 
};