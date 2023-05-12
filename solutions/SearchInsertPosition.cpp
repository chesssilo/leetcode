#include <iostream>
#include <vector> 

class Solution {
public:
    int searchInsert(std::vector<int>& nums, int target) {

        int start = 0;
        int end = nums.size() - 1;

        while (start <= end) {

            int mid = (start + end) / 2;

            if (nums[mid] == target) return mid;

            else if (target > nums[mid]) start = mid + 1;

            else end = mid - 1;
        }
        return end + 1;
    }
};

int main() {
    std::vector<int> nums = { 3,6,7,8,10 };
    int target = 5;
    Solution solution;

    int result = solution.searchInsert(nums, target);

    std::cout << result << std::endl;

    return 0;
}