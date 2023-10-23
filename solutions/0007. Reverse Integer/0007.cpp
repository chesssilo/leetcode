// Time complexity: O(logx)
// Space complexity: O(1)
class Solution {
    static_assert(INT_MAX == 2'147'483'647);
    static_assert(INT_MIN == -2'147'483'647 - 1);
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};