// Time complexity: O(1)
// Space complexity: O(1)
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        n = (n >> 16) | (n << 16);
        {
            uint32_t hi = n & 0xFF00FF00;
            uint32_t lo = n & 0x00FF00FF;
            n = (hi >> 8) | (lo << 8);
        }
        {
            uint32_t hi = n & 0xF0F0F0F0;
            uint32_t lo = n & 0x0F0F0F0F;
            n = (hi >> 4) | (lo << 4); 
        }
        {
            uint32_t hi = n & 0xCCCCCCCC;
            uint32_t lo = n & 0x33333333;
            n = (hi >> 2) | (lo << 2); 
        }
        {
            uint32_t hi = n & 0xAAAAAAAA;
            uint32_t lo = n & 0x55555555;
            n = (hi >> 1) | (lo << 1); 
        }
        return n;
    }
};