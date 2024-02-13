// Time complexity: O(nm)
// Space complexity: O(1)
class Solution {
public:
  string firstPalindrome(const vector<string>& words) {
    for (const string word : words)
      if(isPalindrom(word))
        return word;

      return "";
    }
private:
  bool isPalindrom(const string& word) {
    int left = 0;
    int right = word.length() - 1;
    while (left <= right)
      if (word[left++] != word[right--])
        return false;

    return true;
  }    
};