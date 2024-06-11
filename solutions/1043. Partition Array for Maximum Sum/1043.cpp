// Time complexity: O(nk)
// Space complexity: O(n)
class Solution {
 public:
  int maxSumAfterPartitioning(const vector<int>& arr, int k) {
    int n = arr.size();
    vector<int> maxSum(n + 1, 0);

    for (int start = n - 1; start >= 0; --start) {
      int currMax = 0;
      for (int i = start; i < min(n, start + k); ++i) {
        currMax = max(currMax, arr[i]);
        maxSum[start] = max(maxSum[start], 
                            maxSum[i + 1] + currMax * (i - start + 1));
      }
    }

    return maxSum[0];
  }
};