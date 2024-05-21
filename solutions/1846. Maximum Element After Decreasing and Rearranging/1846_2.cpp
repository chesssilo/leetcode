// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
 public:
  int maximumElementAfterDecrementingAndRearranging(const vector<int>& arr) {
    int n = arr.size();
    vector<int> counts = vector(n + 1, 0);

    for (const int num : arr)
      ++counts[min(num, n)];

    int ans = 1;
    for (int num = 2; num <= n; ++num)
      ans = min(ans + counts[num], num);

    return ans;
  }
};