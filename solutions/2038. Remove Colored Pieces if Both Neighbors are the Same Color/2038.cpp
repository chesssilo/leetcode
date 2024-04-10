// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  bool winnerOfGame(string_view colors) {
    int countAlice = 0;
    int countBob = 0;
        
    for (int i = 1; i < colors.size() - 1; ++i)
      if (colors[i - 1] == colors[i] && colors[i] == colors[i + 1])
        if (colors[i] == 'A')
          ++countAlice;
        else
          ++countBob;
        
    return countAlice > countBob;
  }
};