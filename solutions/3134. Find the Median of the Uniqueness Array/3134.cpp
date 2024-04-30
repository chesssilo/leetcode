// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
 public:
  int medianOfUniquenessArray(const vector<int>& nums) {
    int n = nums.size();
    long long totalSubarrays = static_cast<long long>(n) * (n + 1) / 2;
    int left = 1;
    int right = n;

    while (left < right) {
      int mid = left + (right - left) / 2;
      if (countAtLeastKDistinct(nums, mid) * 2 >= totalSubarrays)
        right = mid;
      else
        left = mid + 1;
    }

    return left;
  }
 private:
  long long countAtLeastKDistinct(const vector<int>& nums, int k) {
    long long count = 0;
    int left = 0;
    unordered_map<int, int> freq;

    for (int right = 0; right < nums.size(); ++right) {
      ++freq[nums[right]];

      while (freq.size() > k) {
        freq[nums[left]]--;
        if (freq[nums[left]] == 0)
          freq.erase(nums[left]);
        ++left;
      }

      count += right - left + 1;
    }

    return count;
  }
};