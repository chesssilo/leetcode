// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  bool isIsomorphic(string_view s, string_view t) {
    vector<int> mapS(128);
    vector<int> mapT(128);

    for (int i = 0; i < s.length(); ++i) {
      if (mapS[s[i]] != mapT[t[i]])
        return false;
      mapS[s[i]] = i + 1;
      mapT[t[i]] = i + 1;    
    }

    return true;
  }
};