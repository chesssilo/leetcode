// Time complexity: O(nm)
// Space complexity: O(n)
struct Trie {
  Trie* children[26] = {};
  int minSize = INT_MAX;
  int bestIndex = 0;

  void insert(const string& word, int index, int j) {
    if (minSize > word.length()) {
      bestIndex = index;
      minSize = word.length();
    }
    if (j < 0)
      return;
    if (children[word[j] - 'a'] == nullptr)
      children[word[j] - 'a'] = new Trie();
    children[word[j] - 'a']->insert(word, index, j - 1);    
  }

  int find(const string& query, int j) {
    if (j >= 0 && children[query[j] - 'a'] != nullptr)
      return children[query[j] - 'a']->find(query, j - 1);

    return bestIndex;  
  }

  ~Trie() {
    for (int i = 0; i < 26; ++i)
      delete children[i];
  }
};

class Solution {
 public:
  vector<int> stringIndices(const vector<string>& wordsContainer, 
                            const vector<string>& wordsQuery) {
    Trie trie;
    for (int i = 0; i < wordsContainer.size(); ++i)
      trie.insert(wordsContainer[i], i, wordsContainer[i].length() - 1);

    vector<int> ans;
    for(const auto& query : wordsQuery)
      ans.push_back(trie.find(query, query.length() - 1));

    return ans;                              
  }
};