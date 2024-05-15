// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
 public:
  bool uniqueOccurrences(const vector<int>& arr) {
    unordered_map<int, int> count;
    unordered_set<int> unique;

    for (const int a : arr)
      ++count[a];

    for (const auto& [_, value] : count)
      if (!unique.insert(value).second)
        return false;
        
    return true;
  }
};