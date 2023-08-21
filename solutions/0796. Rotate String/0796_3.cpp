// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    bool rotateString(const string &s, const string &goal) {
        if (s.size() != goal.size()) {
            return false;
        }
        size_t n = s.size();
        vector<size_t> prefix(1 + n, 0);
        size_t len = 0;
        for (size_t i = 1; i < n; ++i) {
            while (true) {
                if (goal[len] == s[i]) {
                    len++;
                    break;
                }
                if (len == 0) {
                    break;
                }
                len = prefix[len];
            }
            prefix[i + 1] = len;
        }
        len = 0;
        for (size_t i = 0; i < 2 * n; ++i) {
            while (true) {
                if (goal[len] == s[i % n]) {
                    len++;
                    break;
                }
                if (len == 0) {
                    break;
                }
                len = prefix[len];
            }
            if (len == n) {
                return true;
            }
        }
        return false;
    }
}; 