class Solution {
  public int singleNumber(int[] nums) {
    int count[] = new int[32];
    for (int x : nums) {
      for (int i = 0; i < 32; ++i) {
        if ((x & 1) == 1)
          count[i]++;
        x >>= 1;  
      }
    }
    int result = 0;
    for (int i = 0; i < 32; ++i) {
      if (count[i] % 3 != 0)
        result += (1 << i);
      }
    return result;
  }
}