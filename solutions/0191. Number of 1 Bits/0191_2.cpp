// Time Complexity: O(1)
// Space Complexity: O(1)
#pragma GCC target("popcnt")

class Solution {
public:
    int hammingWeight(uint32_t n) {
        return __builtin_popcount(n);    
    }
};