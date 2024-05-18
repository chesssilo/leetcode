// Time complexity: O(1)
// Space complexity: O(1)
class Solution {
 public:
  int minFlips(int a, int b, int c) {
    return bitset<32>((a | b) ^ c).count() + bitset<32>((a & b) & ~c).count();  
  }
};