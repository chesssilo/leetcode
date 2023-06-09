#include <iostream>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int sellOne = 0;
        int holdOne = INT_MIN;

        for (const int price : prices) {
            sellOne = std::max(sellOne, holdOne + price);
            holdOne = std::max(holdOne, -price);
        }
        return sellOne;
    }
};

int main() {
    std::vector<int> prices = { 7, 1, 5, 3, 6, 4 };
    Solution solution;
    int result = solution.maxProfit(prices);
    std::cout << result << std::endl;

	return 0;
}