// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
 public:
  vector<int> findArray(const vector<int>& pref) {
    vector<int> arr(pref.size());
    
    arr[0] = pref[0];
    for (int i = 1; i < pref.size(); ++i)
      arr[i] = pref[i] ^ pref[i - 1];

    return arr;
  }
};