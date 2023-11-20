// Time complexity: O(nm)
// Space complexity: O(1)
class Solution {
public:
    bool repeatedSubstringPattern(const string &s) {
        for (int period = 1; 2 * period <= s.length(); ++period) {
            if (s.length() % period == 0) {
                bool good = true;
                for (int i = period; i < s.length(); ++i) {
                    if (s[i] != s[i - period]) {
                        good = false;
                        break;
                    }
                }
                if (good) {
                    return true;
                }
            }
        }

        return false;   
    }
};