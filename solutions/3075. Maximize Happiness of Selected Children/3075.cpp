// Time complexity: O(nlogn)
// Space complexity: O(1)
class Solution {
public:
  long long maximumHappinessSum(vector<int>& happiness, int k) {
    sort(happiness.begin(), happiness.end(), greater<int>());
    long long count = 0;
    long long sum = 0;
        
    for (int i = 0; i < k; ++i) {
      if (happiness[i] - count < 0)
        return sum;

      sum += happiness[i] - count;
      ++count;
    }
        
    return sum;
  }
};