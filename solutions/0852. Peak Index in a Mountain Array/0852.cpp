// Time complexity: O(log⁡n)
// Space complexity: O(1)
class Solution {
 public:
  int peakIndexInMountainArray(const vector<int>& arr) {
    int l = 0;
    int r = arr.size() - 1;

    while (l < r) {
      const int m = l + (r - l) / 2;
      if (arr[m] >= arr[m + 1])
        r = m;
      else
        l = m + 1;
    }

    return l;
  }
};