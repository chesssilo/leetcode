// Time complexity: O(sort)
// Space complexity: O(n)
class Solution {
 public:
  vector<string> sortPeople(
    const vector<string>& names, 
    const vector<int>& heights
  ) {
    vector<string> ans;
    vector<pair<int, string>> heightAndNames;

    for (int i = 0; i < names.size(); ++i)
      heightAndNames.emplace_back(heights[i], names[i]);

    ranges::sort(heightAndNames, greater<>());

    for (const auto& [_, name] : heightAndNames)
      ans.push_back(name);

    return ans;
  }
};