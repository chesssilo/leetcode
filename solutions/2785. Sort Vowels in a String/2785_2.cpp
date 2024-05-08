// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
 public:
  string sortVowels(const string &s) {
    vector<int> count(128, 0);
    for (const char c : s)
      if (isVowel(c))
        ++count[c];

    string ans;
    int j = 0;
    for (int i = 0; i < s.size(); ++i)
      if (!isVowel(s[i])) {
        ans += s[i];
      } else {
        while (count[kVowels[j]] == 0)
          ++j;

        ans += kVowels[j];
        count[kVowels[j]]--;
      }

    return ans;
  }
 private:
  static constexpr string_view kVowels = "AEIOUaeiou";

  bool isVowel(const char& c) {
    return kVowels.find(c) != string_view::npos;
  }
};