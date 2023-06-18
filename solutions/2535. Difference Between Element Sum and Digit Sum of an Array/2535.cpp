class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int Sum = accumulate(nums.begin(), nums.end(), 0);
        int SumNum = 0;
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] > 9) {
                int temp = nums[i] % 10;
                SumNum += temp;
                nums[i] /= 10;
            }
            SumNum += nums[i];
        }
        return abs(Sum - SumNum);
    }
};