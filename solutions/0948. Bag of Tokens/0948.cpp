// Time complexity: O(sort)
// Space complexity: O(sort)
class Solution {
public:
  int bagOfTokensScore(vector<int>& tokens, int power) {
    int ans = 0;
    int score = 0;
    int left = 0;
    int right = tokens.size() - 1;

    ranges::sort(tokens);

    while (left <= right && (power >= tokens[left] || score)) {
      while (left <= right && power >= tokens[left]) {
        power -= tokens[left++];
        ++score;
      }
      ans = max(ans, score);
      if (left <= right && score) {
        power += tokens[right--];
        --score;
      }
    }

    return ans;
  }
};