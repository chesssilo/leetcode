class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
      vector<int> result;
      int leftSum = 0;
      int rightSum = accumulate(begin(nums), end(nums), 0);

      for (const int num : nums) {
        rightSum -= num;
        result.push_back(abs(leftSum - rightSum));
        leftSum += num;
      }
      return result;
  }  
};