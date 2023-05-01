#include <iostream>
#include <vector>

class Solution
{
public:
	std::vector<int> twoSum(std::vector<int>& nums, int target){
		std::vector<int> v;

		for (int i = 0; i < nums.size(); i++){
			for (int j = 0; j < nums.size(); j++){
				if (i != j){
					if (nums[i] + nums[j] == target) v.push_back(i);
				}
			}
		}
		return v;
	}
};

int main()
{
	std::vector<int> nums{ 2,7,11,15 };
	int target = 9;

	Solution solution;
	std::vector<int> result = solution.twoSum(nums, target);

	for (int i : result)
		std::cout << i << std::endl;

	return 0;
}
