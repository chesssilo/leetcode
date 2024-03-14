// Time complexity: O(1)
// Space complexity: O(1)
class Solution {
 public:
  int pivotInteger(int n) {
    const int sum = (n * (n + 1) / 2);
    const int pivot = sqrt(sum);

    return pivot * pivot == sum ? pivot : -1;
  }
};