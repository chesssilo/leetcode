#include <iostream>
#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {

        int n = nums.size();
        int j = 0;

        for (int i = 0; i < n; i++)
        {
            if (i < n - 1 && nums[i] == nums[i + 1]) {
                continue;
            }
            nums[j++] = nums[i];
        }
        return j;
    }
};

int main() {
    std::vector<int> nums = { 0,0,1,1,1,2,2,3,3,4 };
    Solution solution;

    int result = solution.removeDuplicates(nums);

    std::cout << result << std::endl;

    return 0;
}