// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  bool threeConsecutiveOdds(const vector<int>& arr) {
    int count = 0;
    for (const int a : arr) {
      count = a % 2 == 1 ? count + 1 : 0;
      if (count == 3)
        return true;
    }
    return false;
  }
};