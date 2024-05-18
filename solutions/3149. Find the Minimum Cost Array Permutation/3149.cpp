// Time complexity: O(n*2^n)
// Space complexity: O(n*2^n)
class Solution {
 public:
  vector<int> findPermutation(const vector<int>& nums) {
    const int n = nums.size();
    vector<vector<int>> mem(n, vector<int>(1 << n));
    vector<vector<int>> bestPick(n, vector<int>(1 << n));

    getScore(nums, 0, 1, bestPick, mem);

    return construct(bestPick);
  }
 private:
  int getScore(const vector<int>& nums, int last, unsigned mask, 
                vector<vector<int>>& bestPick, vector<vector<int>>& mem) {
    if (popcount(mask) == nums.size())
      return abs(last - nums[0]);
    if (mem[last][mask] > 0)
      return mem[last][mask];

    int minScore = INT_MAX;
    for (int i = 1; i < nums.size(); ++i) {
      if (mask >> i & 1)
        continue;
      const int nextMinScore = abs(last - nums[i]) + 
                               getScore(nums, i, mask | 1 << i, bestPick, mem);
      if (nextMinScore < minScore) {
        minScore = nextMinScore;
        bestPick[last][mask] = i;
      }
    }

    return mem[last][mask] = minScore;
  }

  vector<int> construct(const vector<vector<int>>& bestPick) {
    vector<int> ans;
    int last = 0;
    int mask = 1;
    for (int i = 0; i < bestPick.size(); ++i) {
      ans.push_back(last);
      last = bestPick[last][mask];
      mask |= 1 << last;
    }

    return ans;
  }
};