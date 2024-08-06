// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
 public:
  string kthDistinct(const vector<string>& arr, int k) {
    unordered_map<string_view, int> count;

    for (const string_view a : arr)
      ++count[a];

    for (const string a : arr)
      if (count[a] == 1 && --k == 0)
        return a;

    return "";
  }
};