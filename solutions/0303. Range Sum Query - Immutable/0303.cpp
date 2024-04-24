// Time complexity: O(n)
// Space complexity: O(n)
class NumArray {
 public:
  NumArray(const vector<int>& nums) : prefix(nums.size() + 1) {
    partial_sum(nums.begin(), nums.end(), prefix.begin() + 1);
  }
    
  int sumRange(const int left, const int right) {
    return prefix[right + 1] - prefix[left];
  }
  
 private:
  vector<int> prefix;    
};