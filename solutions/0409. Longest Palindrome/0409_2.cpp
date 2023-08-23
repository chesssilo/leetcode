// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int longestPalindrome(const string &s) {
        unordered_map<char, int> count;
        for (char c : s) {
            count[c]++;
        }
        int even = 0;
        int odd = 0;
        for (auto const &kv : count) {
            int c = kv.first;
            even += count[c] & (~1);
            odd |= count[c] & 1;
        }
        return even + odd;
    }
};