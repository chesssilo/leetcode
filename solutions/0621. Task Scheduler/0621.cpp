// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  int leastInterval(const vector<char>& tasks, int n) {
    if (n == 0)
      return tasks.size();

    vector<int> count(26);

    for (const char task : tasks)
      ++count[task -'A'];

    const int maxFreq = ranges::max(count);
    const int maxFreqTaskOccupy = (maxFreq - 1) * (n + 1);
    const int nMaxfreq = ranges::count(count, maxFreq);

    return max(maxFreqTaskOccupy + nMaxfreq, static_cast<int>(tasks.size()));       
  }
};