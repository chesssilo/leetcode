// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    char findTheDifference(const string &s, const string &t) {
        char ans = 0;
        for (char c : s) {
            ans ^= c;
        }
        for (char c : t) {
            ans ^= c;
        }

        return ans;
    }
};