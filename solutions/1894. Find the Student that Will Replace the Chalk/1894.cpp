// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  int chalkReplacer(const vector<int>& chalk, int k) {
    k %= accumulate(chalk.begin(), chalk.end(), 0L);
    if (k == 0)
      return 0;

    for (int i = 0; i < chalk.size(); ++i) {
      if (k < chalk[i])
        return i;
      k -= chalk[i];
    }

    return 0;
  }
};