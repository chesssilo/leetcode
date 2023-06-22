// Time Complexity: O(1).
// Space Complexity: O(1).
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n) {
            ++count;
            n &= n - 1;
        }
        return count;
    }
};