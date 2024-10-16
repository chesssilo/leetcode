// Time complexity: O(nm)
// Space complexity: O(k)
class Solution {
 public:
  vector<int> findWordsContaining(const vector<string>& words, char x) {
    vector<int> ans;

    for (int i = 0; i < words.size(); ++i)
      if (words[i].find(x) != string::npos)
        ans.push_back(i);

    return ans;
  }
};