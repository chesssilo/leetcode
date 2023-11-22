// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    bool isSubsequence(string_view s, string_view t) {
        if (s.empty()) {
            return true;
        }
    
        int i = 0;
        for (const char c : t) {
            if (s[i] == c && ++i == s.length()) {
                return true;
            }   
        }
        return false;
    }
};