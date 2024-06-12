// Time complexity: O(n+m)
// Space complexity: O(n)
class Solution {
 public:
  vector<int> relativeSortArray(const vector<int>& arr1, 
                                const vector<int>& arr2) {
    vector<int> ans;
    vector<int> count(1001);

    for (const int a : arr1)
      ++count[a];

    for (const int a : arr2)
      while (count[a]-- > 0)
        ans.push_back(a);

    for (int num = 0; num < 1001; ++num)
      while (count[num]-- > 0)
        ans.push_back(num);

    return ans;
  }
};