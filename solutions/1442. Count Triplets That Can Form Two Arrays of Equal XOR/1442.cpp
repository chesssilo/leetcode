// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
 public:
  int countTriplets(const vector<int>& arr) {
    int ans = 0;
    int pref = 0;
    unordered_map<int, int> countMap = {{0, 1}};
    unordered_map<int, int> totalMap;

    for (int i = 0; i < arr.size(); ++i) {
      pref ^= arr[i];
      ans += countMap[pref]++ * i - totalMap[pref];
      totalMap[pref] += i + 1;
    }

    return ans;
  }
};