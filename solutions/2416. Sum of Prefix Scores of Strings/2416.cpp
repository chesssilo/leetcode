// Time complexity: O(mn)
// Space complexity: O(mn)
struct TrieNode {
  TrieNode* next[26] = {};
  int count = 0;
};

class Solution {
 public:
  vector<int> sumPrefixScores(const vector<string>& words) {
    int n = words.size();
    vector<int> ans(n, 0);

    for (int i = 0; i < n; ++i)
      insert(words[i]);

    for (int i = 0; i < n; ++i)
      ans[i] = count(words[i]);

    return ans;
  }

 private:
  TrieNode root;

  void insert(string_view word) {
    auto node = &root;

    for (const char c : word) {
      if (!node->next[c - 'a'])
        node->next[c - 'a'] = new TrieNode();

      ++node->next[c - 'a']->count;
      node = node->next[c - 'a'];
    }
  }

  int count(string_view word) {
    auto node = &root;
    int res = 0;

    for (const char c : word) {
      res += node->next[c - 'a']->count;
      node = node->next[c - 'a'];
    }

    return res;
  }
};