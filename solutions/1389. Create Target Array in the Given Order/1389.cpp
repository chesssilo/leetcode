class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        vector<int> result;

        for (int i = 0; i < size(nums); i++)
            result.emplace(result.begin() + index[i], nums[i]);

        return result;
    }
};