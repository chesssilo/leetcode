// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  bool isValid(string_view word) {
    return word.length() >= 3 &&
           ranges::all_of(word, [](char c) { return isalnum(c); }) &&
           ranges::any_of(word, isVowel) && ranges::any_of(word, isConsonant);
  }

 private:
  static bool isVowel(char c) {
    static constexpr string_view kVolwels = "aeiouAEIOU";
    return kVolwels.find(c) != string_view::npos;
  }

  static bool isConsonant(char c) {
    return isalpha(c) && !isVowel(c);
  }
};