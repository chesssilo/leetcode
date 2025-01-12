// Time complexity: O((n+m)logn)
// Space complexity: O(n+m)
class Solution {
 public:
  vector<int> fullBloomFlowers(
    vector<vector<int>>& flowers, vector<int>& people
  ) {
    vector<int> ans;
    vector<int> starts;
    vector<int> ends;

    for (const vector<int>& flower : flowers) {
      starts.push_back(flower[0]);
      ends.push_back(flower[1]);
    }

    ranges::sort(starts);
    ranges::sort(ends);

    for (const int p : people) {
      const int started = ranges::upper_bound(starts, p) - starts.begin();
      const int ended = ranges::lower_bound(ends, p) - ends.begin();
      ans.push_back(started - ended);
    }

    return ans;
  }
};