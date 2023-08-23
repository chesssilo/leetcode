// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int longestPalindrome(const string &s) {
        int count[1 + 'z'] = {};
        for (char c : s) {
            count[c]++;
        }
        int even = 0;
        int odd = 0;
        for (int c = 'A'; c <= 'z'; ++c) {
            even += count[c] & (~1);
            odd |= count[c] & 1;
        }
        return even + odd;
    }
};