#include <iostream>

class Solution {
public:
    int mySqrt(int x) {
        int left = 0;
        int right = 46340;
        int middle, result;

        while (left <= right) {
            if (left * left == x) return left;
            if (right * right == x) return right;
            
            middle = left + ((right - left) / 2);
            result = middle * middle;
            if (result == x)
                return middle;
            else if (result < x)
                left = middle + 1;
            else
                right = middle - 1;
        }
        return right;
    }
};

int main() {
    Solution solution;
    int result = solution.mySqrt(144);
    std::cout << result << std::endl;

	return 0;
}