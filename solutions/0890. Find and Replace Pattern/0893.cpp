// Time complexity: O(nk)
// Space complexity: O(n)
class Solution {
 public:
  vector<string> findAndReplacePattern(const vector<string>& words, string_view pattern) {
    vector<string> ans;

    for (const string& word : words)
      if (isIsomorphic(word, pattern))
        ans.push_back(word);

    return ans;        
  }
 private:
  bool isIsomorphic(string_view w, string_view p) {
    vector<int> mapW(128);
    vector<int> mapP(128);

    for (int i = 0; i < w.length(); ++i) {
      if (mapW[w[i]] != mapP[p[i]])
        return false;
      mapW[w[i]] = i + 1;
      mapP[p[i]] = i + 1;    
    }

    return true;
  }
};