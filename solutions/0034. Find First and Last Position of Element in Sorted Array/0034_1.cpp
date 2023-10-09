// Time complexity: O(logn)
// Space complexity: O(1)
class Solution {
public:
    vector<int> searchRange(const vector<int>& nums, int target) {
        auto first = lower_bound(nums.begin(), nums.end(), target);
        if (first == nums.end() || *first != target) {
            return {-1, -1};
        }
        auto after = upper_bound(nums.begin(), nums.end(), target);
        return {int(first - nums.begin()), int(after - nums.begin() - 1)};
    }
};