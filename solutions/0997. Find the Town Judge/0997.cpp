// Time complexity: O(n + trust)
// Space complexity: O(n)
class Solution {
public:
  int findJudge(int n,const vector<vector<int>>& trust) {
    vector<int> count(n + 1);

    for (const vector<int>& t : trust) {
      --count[t[0]];
      ++count[t[1]];
    }

    for (int i = 1; i < n + 1; ++i)
      if (count[i] == n - 1)
        return i;

    return -1;       
  }
};