// Time complexity: O(logn)
// Space complexity: O(1)
class Solution {
public:
    vector<int> searchRange(const vector<int>& nums, int target) {
        int first = firstIndex(nums, target);
        if (first == nums.size() || nums[first] != target){
            return {-1, -1};
        }
        int last = lastIndex(nums, target);
        return {first, last};
    }

private: 
    int firstIndex(const vector<int>& nums, int target) {
        int left = -1;
        int right = (int)nums.size();
        while (left + 1 < right){
            int mid = (left + right) / 2;
            if (nums[mid] < target){
                left = mid;
            } else {
                right = mid;
            }
        }
        return right;
    }

    int lastIndex(const vector<int>& nums, int target) {
        int left = -1;
        int right = (int)nums.size();
        while (left + 1 < right){
            int mid = (left + right) / 2;
            if (nums[mid] <= target){
                left = mid;
            } else {
                right = mid;
            }
        }
        return left;
    }
};