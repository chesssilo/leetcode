// Time Complexity: O(1)
// Space complexity: O(1)
class Solution {
public:
    bool hasAlternatingBits(unsigned int n) {
        unsigned int ones = n ^ (n >> 1);
        return (ones & (ones + 1)) == 0; 
    }
};