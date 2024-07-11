// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  int minOperations(const vector<string>& logs) {
    int ans = 0;

    for (const string& log : logs) {
      if (log == "./")
        continue;
      if (log == "../")
        ans = max(0, ans - 1);
      else
        ++ans;
    }

    return ans;
  }
};