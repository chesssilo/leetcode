// Time complexity: O(n4^n)
// Space complexity: O(4^n)
class Solution {
public:
  vector<string> letterCombinations(string_view digits) {
    if (digits.empty())
      return {};

    vector<string> ans{""};
    vector<string> digitToLetters{"", "", "abc", "def", "ghi", "jkl",
                                  "mno", "pqrs", "tuv", "wxyz"};

    for (const char d : digits) {
      vector<string> temp;
      for (const string& s : ans)
        for (const char c : digitToLetters[d - '0'])
          temp.push_back(s + c);
      ans = move(temp);    
    }

    return ans;
  }
};