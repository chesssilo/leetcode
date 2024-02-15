// Time complexity: O(sort)
// Space complexity: O(sort)
class Solution {
public:
  long long largestPerimeter(vector<int>& nums) {
    ranges::sort(nums);
    long long previousElementsSum = 0;
    long long ans = -1;
    for (int num : nums) {
      if (num < previousElementsSum)
        ans = num + previousElementsSum;

      previousElementsSum += num;
    }

    return ans;
  }
};