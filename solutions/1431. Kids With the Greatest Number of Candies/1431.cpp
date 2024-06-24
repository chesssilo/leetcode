// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
 public:
  vector<bool> kidsWithCandies(const vector<int>& candies, int extraCandies) {
    vector<bool> ans;
    int maxCandies = 0;

    for (const int candy : candies)
      maxCandies = max(maxCandies, candy);

    for (const int candy : candies)
      ans.push_back(candy + extraCandies >= maxCandies);

    return ans;
  }
};