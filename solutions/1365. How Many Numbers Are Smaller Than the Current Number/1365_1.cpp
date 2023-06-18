class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> result;
        for (int i = 0; i < nums.size(); i++) {
            int temp = 0;
            for (int j = 0; j < nums.size(); j++) {
                if (nums[i] > nums[j])
                    ++temp;
            }
            result.push_back(temp);
        }
        return result;
    }
};