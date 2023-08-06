class Solution {
public:
  int binaryGap(int n) {
     if ((n & (n - 1)) == 0) {
      return 0;
     }
     n |= n - 1;
     int ans = 1;
     while ((n & (n + 1)) != 0) {
      n |= n >> 1;
      ans++;
     }    
     return ans;
  }
};