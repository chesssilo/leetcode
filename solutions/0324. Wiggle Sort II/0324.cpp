class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> arr = nums;
        int p = (nums.size() - 1) / 2, q = nums.size() - 1;
        for (int i = 0, j = 1; i < nums.size(); i += 2, j += 2) {
            nums[i] = arr[p--];
            if (j < nums.size()) nums[j] = arr[q--];
        }
    }
};