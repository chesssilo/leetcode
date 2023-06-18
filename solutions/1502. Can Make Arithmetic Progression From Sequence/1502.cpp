// Time complexity: O(nlog⁡n)
// Space complexity: O(n)
class Solution {
public:
  bool canMakeArithmeticProgression(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    int delt = arr[1] - arr[0];
    for (int i = 2; i < size(arr); i++) 
      if (arr[i] - arr[i - 1] != delt) return false;

    return true;
    }
};