class Solution {
public:
    int binaryGap(int n) {
      while ((n & 1) == 0) {
        n >>= 1;
      }
      n >>= 1;
      int ans = 0;
      int lastDistance = 1;
      while ( n != 0) {
        int bit = n & 1;
        n >>= 1;
        if (bit == 1) {
          ans = max(ans, lastDistance);
          lastDistance = 1;
        } else {
          lastDistance++;
        }
      }
      return ans;  
    }
};