#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        int n = digits.size();

        for (int i = n - 1; i >= 0; i--) {
            if (digits[i] < 9) {
                digits[i]++; 
                return digits;
            } else digits[i] = 0;
        }
        std::vector<int>result(n + 1, 0);
        result[0] = 1;
        return result;
    }
};

int main() {
    std::vector<int> digits = { 4, 3, 2, 1 };
    Solution solution;
    auto result = solution.plusOne(digits);

    for (int iter : result)
        std::cout << iter << " ";

    return 0;
}