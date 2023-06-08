#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> getRow(int rowIndex) {
        std::vector<int> ans(rowIndex + 1, 1);

        for (int i = 2; i < rowIndex + 1; ++i)
            for (int j = 1; j < i; ++j)
                ans[i - j] += ans[i - j - 1];

        return ans;
    }
};

int main() {
    int rowIndex = 5;
    Solution solution;
    auto result = solution.getRow(rowIndex);

    for (int item : result)
        std::cout << item << std::endl;
  
	return 0;
}