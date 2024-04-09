// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  bool halvesAreAlike(string_view s) {
    string kVowels = "aeiuoAEIOU";
    int vowelsCount = 0;

    for(int i = 0; i < s.length(); ++i)
      if(kVowels.find_first_of(s[i]) != string::npos)
        vowelsCount = i < s.length() / 2 ? vowelsCount + 1 : vowelsCount - 1;
            
    return vowelsCount == 0; 
  }
};