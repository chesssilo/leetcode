// Time complexity: O(n+mlogm)
// Space complexity: O(1)
class Solution {
public:
  int minimumBoxes(const vector<int>& apple, vector<int>& capacity) {
    int sum = accumulate(apple.begin(), apple.end(), 0);
    int i = 0;
    sort(capacity.begin(), capacity.end(), greater<int>());
        
    for ( ; i < capacity.size() && sum > 0; ++i) 
      sum -= capacity[i];

    return i;
  }
};