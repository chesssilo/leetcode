// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    char findTheDifference(const string &s, const string &t) {
        int sum = 0;
        for (char c : s) {
            sum -= c;
        }
        for (char c : t) {
            sum += c;
        }

        return (char)sum;
    }
};