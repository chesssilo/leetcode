// Time complexity: O(n^2)
// Space complexity: O(n)
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        return (s + s).find(s, 1) < s.length();
    }
};