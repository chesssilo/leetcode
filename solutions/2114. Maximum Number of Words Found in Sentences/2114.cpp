// Time complexity: O(nm)
// Space complexity: O(1)
class Solution {
 public:
  int mostWordsFound(const vector<string>& sentences) {
    long maxSpaceCount = 0;

    for (const string& s : sentences)
      maxSpaceCount = max(maxSpaceCount, ranges::count(s, ' '));

    return maxSpaceCount + 1;
  }
};