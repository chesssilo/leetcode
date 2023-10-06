// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    int integerBreak(int n) {
        if ( n <= 3) {
            return n - 1;
        }

        int ans = 1;

        while (n > 4) {
            ans *= 3;
            n -= 3;
        }

        return ans * n;
    }
};