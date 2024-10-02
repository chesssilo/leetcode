// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  bool canArrange(const vector<int>& arr, int k) {
    vector<int> count;

    for (int a : arr) {
      a %= k;
      ++count[a < 0 ? a + k : a];
    }

    if (count[0] % 2 != 0)
      return false;

    for (int i = 1; i <= k / 2; ++i)
      if (count[i] != count[k - i])
        return false;

    return true;
  }
};