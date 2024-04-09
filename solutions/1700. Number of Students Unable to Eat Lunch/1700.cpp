// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  int countStudents(const vector<int>& students, const vector<int>& sandwiches) {
    vector<int> count(2);

    for (const int student : students)
      ++count[student];

    for (int i = 0; i < sandwiches.size(); ++i) {
      if (count[sandwiches[i]] == 0)
        return sandwiches.size() - i;
      --count[sandwiches[i]];    
    }

    return 0;
  }
};