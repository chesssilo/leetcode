#include <iostream>
#include <vector>

class Solution {
public:
    int removeElement(std::vector<int>& nums, int val) {
        
        int k = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val)
                nums[k++] = nums[i];
        }
        return k;
    }
};

int main() {
    std::vector<int> nums = { 3,2,2,3 };
    int val = 3;
    Solution solution;
    int result = solution.removeElement(nums,val);
    std::cout << result << std::endl;
    return 0;
}