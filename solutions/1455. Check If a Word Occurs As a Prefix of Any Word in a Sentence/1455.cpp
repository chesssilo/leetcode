// Time complexity: O(n+mk)
// Space complexity: O(n)
class Solution {
 public:
  int isPrefixOfWord(const string& sentence, string_view searchWord) {
    istringstream stream(sentence);
    string word;
    int index = 1;

    while (stream >> word) {
      if (word.find(searchWord) == 0)
        return index;
      ++index;
    }

    return -1;
  }
};