#include <iostream>

class Solution {
public:
    bool isPalindrome(std::string s) {
        std::string temp;

        for (char i : s) {    
            if ((48 <= i && i <= 57) || (65 <= i && i <= 90) || (97 <= i && i <= 122))
                temp += tolower(i);
        }
        s = temp;

        for (int i = 0; i < s.length() / 2; i++) {
            if (s[i] != s[s.length() - i - 1])
                return false;
        }
        return true;
    }
};

int main() {
    std::string s = "A man, a plan, a canal: Panama";
    Solution solution;
    bool result = solution.isPalindrome(s);
    std::cout << result << std::endl;

	return 0;
}