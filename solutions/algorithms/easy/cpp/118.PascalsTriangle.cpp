#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> ans;

        for (int i = 0; i < numRows; ++i)
            ans.push_back(std::vector<int>(i + 1, 1));

        for (int i = 2; i < numRows; ++i)
            for (int j = 1; j < ans[i].size() - 1; ++j)
                ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];

        return ans;
    }
};

int main() {
    int numRows = 7;
    Solution solution;
    auto result = solution.generate(numRows);
    
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < result[i].size(); j++) 
            std::cout << result[i][j] << '\t';
        std::cout << std::endl;
    }

	return 0;
}