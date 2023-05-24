#include <iostream>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {

        auto pos = haystack.find(needle);
        if (pos != std::string::npos)
            return pos;
        else
            return -1;
    }
};

int main() {
    std::string haystack = "Hello";
    std::string needle = "ll";
    Solution solution;
    int result = solution.strStr(haystack, needle);
    std::cout << result << std::endl;
    return 0;
}