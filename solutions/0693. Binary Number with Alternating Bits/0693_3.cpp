// Time Complexity: O(1)
// Space complexity: O(1)
class Solution {
public:
    bool hasAlternatingBits(int n) {
       int pow2 = n - (n >> 2);
       return (pow2 & (pow2 - 1)) == 0;  
        
    }
};