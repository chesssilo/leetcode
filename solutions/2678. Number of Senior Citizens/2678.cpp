// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  int countSeniors(const vector<string>& details) {
    return ranges::count_if(details, [](const string& detail) {
      return stoi(detail.substr(11, 2)) > 60;
    });
  }
};