// Time complexity: O(n+m)
// Space complexity: O(n+m)
class Solution {
 public:
  vector<string> findRelativeRanks(const vector<int>& score) {
    int n = score.size();
    int m = *max_element(score.begin(), score.end());

    vector<int> scoreToIndex(m + 1, 0);
    for (int i = 0; i < n; ++i)
      scoreToIndex[score[i]] = i + 1;

    const vector<string> MEDALS = {"Gold Medal", "Silver Medal", "Bronze Medal"};

    vector<string> ans(n);
    int place = 1;
    for (int i = m; i >= 0; --i)
      if (scoreToIndex[i] != 0) {
        int originalIndex = scoreToIndex[i] - 1;
        if (place < 4)
          ans[originalIndex] = MEDALS[place - 1];
        else
          ans[originalIndex] = to_string(place);
        ++place;
      }

    return ans;   
  }
};