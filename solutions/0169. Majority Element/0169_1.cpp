// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
 public:
  int majorityElement(const vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> count;

    for (int num : nums) {
        count[num]++;
        if (count[num] > n / 2) {
            return num;
        }
    }
    throw invalid_argument("no majority element");
  }
};