// Time complexity: O(nm)
// Space complexity: O(m)
class Solution {
public:
  string firstPalindrome(const vector<string>& words) {
    for (const string word : words) {
      string temp = word;
      reverse(temp.begin(), temp.end());
      if (word == temp)
        return word;
    }

    return "";
  }
};