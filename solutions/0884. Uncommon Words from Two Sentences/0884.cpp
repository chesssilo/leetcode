// Time complexity: O(m+n)
// Space complexity: O(m+n)
class Solution {
 public:
  vector<string> uncommonFromSentences(string s1, string s2) {
    vector<string> ans;
    unordered_map<string, int> count;
    istringstream iss(s1 + ' ' + s2);

    while (iss >> s1)
      ++count[s1];

    for (const auto& [word, freq] : count)
      if (freq == 1)
        ans.push_back(word);

    return ans;
  }
};