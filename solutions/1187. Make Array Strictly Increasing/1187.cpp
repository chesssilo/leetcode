// Time complexity : O(sort)
// Space complexity: O(|arr1|)
class Solution {
 public:
  int makeArrayIncreasing(const vector<int>& arr1, vector<int>& arr2) {
    unordered_map<int, int> dp{{-1, 0}};
    int ans = INT_MAX;

    ranges::sort(arr2);

    for (const int a : arr1) {
      unordered_map<int, int> nextDp;
      for (const auto& [val, steps] : dp) {
        if (a > val)
          nextDp[a] = min(nextDp.count(a) ? nextDp[a] : INT_MAX, steps);
        if (const auto it = ranges::upper_bound(arr2, val); it != arr2.cend())
          nextDp[*it] = 
            min(nextDp.count(*it) ? nextDp[*it] : INT_MAX, steps + 1);
      }
      if (nextDp.empty())
        return -1;
      dp = move(nextDp);
    }

    for (const auto& [_, steps] : dp)
      ans = min(ans, steps);

    return ans;
  }
};