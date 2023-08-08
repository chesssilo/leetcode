// Time Complexity: O(1)
// Space complexity: O(1)
class Solution {
public:
    bool hasAlternatingBits(int n) {
        int last = n & 3;
        if (last != 1 && last != 2) {
            return false;
        }
        n >>= 2;
        while ( n > 0) {
            if ((n & 3) != last) {
                return false;
            }
            n >>= 2;
        }
        return true; 
    }
};