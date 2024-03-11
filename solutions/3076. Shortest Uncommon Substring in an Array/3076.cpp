// Time complexity: O(n*m^2*log(m))
// Space complexity: O(n*m^2)
class Solution {
 public:
  vector<string> shortestSubstrings(vector<string>& arr) {
    vector<vector<string>> subs(arr.size(), vector<string>());
    unordered_map<string, int> map;

    for (int i = 0; i < arr.size(); ++i) {
      for (int j = 0; j < arr[i].length(); ++j) {
        string s = "";
        for (int k = j; k < arr[i].length(); ++k) {
          s += arr[i][k];
          if (find(subs[i].begin(), subs[i].end(), s) != subs[i].end())
            continue;
          ++map[s];
          subs[i].push_back(s);    
        }
      }    
      sort(subs[i].begin(), subs[i].end(), compi);
    }

    vector<string> ans(arr.size(), "");

    for (int i = 0; i < arr.size(); ++i)
      for (auto sub : subs[i])
        if (map[sub] == 1) {
          ans[i] = sub;
          break;
        }

    return ans;        
  }
 private:
  static bool compi(const string& p, const string& q) {
    if (p.size() < q.size() || (p.size() == q.size() && p < q))
      return true;

    return false;
  }
};