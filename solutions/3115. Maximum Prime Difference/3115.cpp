// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  int maximumPrimeDifference(const vector<int>& nums) {
    int l = 0;
    int r = nums.size() - 1;
    int ans = 0;

    while (l < r) {
      if (isPrime(nums[l]) && isPrime(nums[r])) {
        ans = abs(r - l);
        break;
      }

      if (!isPrime(nums[l]))
        ++l;
      if (!isPrime(nums[r]))
        --r;  
    }

    return ans;
  }
 private:
  bool isPrime(int num) {
    if (num <= 1)
      return false;

    for (int i = 2; i <= sqrt(num); ++i)
      if (num % i == 0)
        return false;

    return true;  
  }  
};