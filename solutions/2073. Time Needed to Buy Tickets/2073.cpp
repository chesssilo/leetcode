// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  int timeRequiredToBuy(const vector<int>& tickets, int k) {
    int ans = 0;

    for (int i = 0; i < tickets.size(); ++i)
      if (i <= k)
        ans += min(tickets[i], tickets[k]);
      else
        ans += min(tickets[i], tickets[k] - 1);

    return ans;
  }
};