// Time complexity: O(n^2)
// Space complexity: O(1)
class Solution {
public:
    bool rotateString(const string &s, const string &goal) {
        if (s.size() != goal.size()) {
            return false;
        }
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            bool good = true;
            for (int j = 0; j < n; ++j) {
                int index = (i + j) % n;
                if (s[index] != goal[j]) {
                    good = false; 
                    break
                }
            }
            if (good) {
                return true;
            }
        }
        return false;
    }
};