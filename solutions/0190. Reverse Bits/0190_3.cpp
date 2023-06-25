// Time complexity: O(1)
// Space complexity: O(1)
class Solution {
    static uint16_t reverse16[1 << 16];

public:

    Solution() {
        if (reverse16[1] == 0) {
            uint16_t reverse2[1 << 2] = {0, 2, 1, 3};
            uint16_t reverse4[1 << 4];
            for (int hi = 0; hi < (1 << 2); hi++) {
                for (int lo = 0; lo < (1 << 2); lo++) {
                    reverse4[(hi << 2) | lo] = (reverse2[lo] << 2) | reverse2[hi];
                }
            }
            uint16_t reverse8[ 1 << 8];
            for (int hi = 0; hi < (1 << 4); hi++) {
                for (int lo = 0; lo < (1 << 4); lo++) {
                    reverse8[(hi << 4) | lo] = (reverse4[lo] << 4) | reverse4[hi];
                }
            }
            for (int hi = 0; hi < (1 << 8); hi++) {
                for (int lo = 0; lo < (1 << 8); lo++) {
                    reverse16[(hi << 8) | lo] = (reverse8[lo] << 8) | reverse8[hi];
                }
            }
        }
    } 

    uint32_t reverseBits(uint32_t n) {
        return (reverse16[n & 0xFFFF] << 16) | reverse16[n >> 16];
    }   
};

uint16_t Solution::reverse16[1 << 16];