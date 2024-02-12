// Time complexity: O(n + m)
// Space complexity: O(n)
class Solution {
public:
  int countMatchingSubarrays(const vector<int>& nums, const vector<int>& pattern) {
    vector<int> numsPattern;
    for (int i = 1; i < nums.size(); ++i)
      numsPattern.push_back((0 < nums[i] - nums[i - 1]) - (0 > nums[i] - nums[i - 1]));

    return rabinKarp(numsPattern, pattern);    
  }

private:
  int rabinKarp(const vector<int>& numsPattern, const vector<int>& pattern) {
    static constexpr int p = 31;
    static constexpr int kMod = 1'000'000'001ull;
    long long patternPow = 1;
    long long hT = 0;
    long long hS = 0;
    int res = 0;

    for (int i = 0; i < pattern.size(); ++i) {
      hT = (hT * p + (pattern[i] + 1)) % kMod;
      patternPow = (patternPow * p) % kMod;
    }
    for (int i = 0; i < numsPattern.size(); ++i) {
      hS = (hS * p + (numsPattern[i] + 1)) % kMod;
      if (i >= pattern.size())
        hS = (kMod + hS - patternPow * (numsPattern[i - pattern.size()] + 1) % kMod) % kMod;
      if (i + 1 >= pattern.size() && hT == hS)
        ++res;    
      }

    return res;
    }
};