// Time complexity: O(∣s∣+∣t∣)
// Space complexity: O(1)
class Solution {
public:
    bool backspaceCompare(const string &s, const string &t) {
        int i = s.length() - 1;  
        int j = t.length() - 1;

        while (true) {
            int backspace = 0;
            while (i >= 0 && (s[i] == '#' || backspace > 0)) {
                backspace += s[i] == '#' ? 1 : -1;
                --i;
            }

            backspace = 0;
            while (j >= 0 && (t[j] == '#' || backspace > 0)) {
                backspace += t[j] == '#' ? 1 : -1;
                --j;
            }
            if (i >= 0 && j >= 0 && s[i] == t[j]) {
                --i;
                --j;
            } else {
                break;
            }
        }
        return i == -1 && j == -1;
    }    
};