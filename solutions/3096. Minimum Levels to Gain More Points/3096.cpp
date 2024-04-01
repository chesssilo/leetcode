// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  int minimumLevels(const vector<int>& possible) {
    int bobScore = 0;
    for (const int& num : possible)
      bobScore += (num ? 1 : -1);
        
    int danielScore = 0;
    for (int i = 0; i < possible.size() - 1; ++i) {
      danielScore += (possible[i] ? 1 : -1);
      if (danielScore > bobScore - danielScore)
        return i + 1;
    }
        
    return -1;
  }
};