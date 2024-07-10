// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  double averageWaitingTime(const vector<vector<int>>& customers) {
    double wait = 0;
    double curr = 0;

    for (const vector<int>& customer : customers) {
      curr = max(curr, 1.0 * customer[0]) + customer[1];
      wait += curr - customer[0];
    }

    return 1.0 * wait / customers.size();
  }
};