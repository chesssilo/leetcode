#include <iostream>

class Solution {
public:
    int lengthOfLastWord(std::string s) {
        int lastWordLength = 0;
        std::string lastWord = s;

        lastWord.erase(0, lastWord.find_first_not_of(" "));
        lastWord.erase(lastWord.find_last_not_of(" ") + 1);

        for (int i = 0; i < lastWord.length(); i++) {
            if (lastWord[i] == ' ')
                lastWordLength = 0;
            else
                lastWordLength++;
        }
        return lastWordLength;
    }
};

int main() {
    std::string s = "   fly me   to   the moon  ";
    Solution solutin;
    int result = solutin.lengthOfLastWord(s);
    std::cout << result << std::endl;

    return 0;
}