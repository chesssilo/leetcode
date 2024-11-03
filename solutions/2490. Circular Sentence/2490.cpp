// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  bool isCircularSentence(string_view sentence) {
    for (int i = 0; i < sentence.length(); ++i)
      if (sentence[i] == ' ' && sentence[i - 1] != sentence[i + 1])
        return false;
    return sentence.front() == sentence.back();
  }
};