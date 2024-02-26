// Time complexity: O(nlognlogn)
// Space complexity: O(n)
class Solution {
public:
  int earliestSecondToMarkIndices(const vector<int>& nums, const vector<int>& changeIndices) {
    int m = changeIndices.size();
    if (!Check(nums, changeIndices, m))
      return -1;

    int low = 1;
    int high = m;
    while(low < high) {
      int mid = low + (high - low) / 2;
      if (Check(nums, changeIndices, mid))
        high = mid;
      else
        low = mid + 1;
    }

    return low;   
  }

private:
  bool Check(const vector<int>& nums, const vector<int>& changeIndices, int maxX) {
    int n = nums.size();
    vector<int> earliestSet(n + 1, -1);
    for (int i = 1; i <= maxX; ++i) {
      int change = changeIndices[i - 1];
      if (earliestSet[change] == -1)
        earliestSet[change] = i;
    }

    long long sumTotal = 0;
    for (int num : nums)
      sumTotal += num + 1;

    long long ret = sumTotal;
    vector<pair<int, int>> v;

    for (int change = 1; change <= n; ++change) {
      if (nums[change - 1] == 0 || earliestSet[change] == -1)
        continue;
      v.push_back({nums[change - 1], earliestSet[change]});    
    }

    ranges::sort(v);
    ranges::reverse(v);

    vector<bool> isVacant(maxX + 1, true);

    for (auto i : v) {
      int id = i.second;
      if (!isVacant[id])
        for (int j = id + 1; j <= maxX; ++j)
          if (isVacant[j]) {
            isVacant[id] = true;
            isVacant[j] = false;
            break;
          }
      if (!isVacant[id])
        continue;

      for (int j = id + 1; j <= maxX; ++j)
        if (isVacant[j]) {
          isVacant[id] = false;
          isVacant[j] = false;
          ret -= i.first - 1;
          break;
        }         
    }

    return ret <= maxX;
  }
};
