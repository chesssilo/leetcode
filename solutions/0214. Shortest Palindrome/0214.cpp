// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
 public:
  string shortestPalindrome(string s) {
    long long hashBase = 29;
    long long kMod = 1'000'000'007;
    long long forwHash = 0;
    long long revHash = 0;
    long long powVal = 1;
    int index = -1;

    for (int i = 0; i < s.length(); ++i) {
      char currChar = s[i];
      forwHash = (forwHash * hashBase + (currChar - 'a' + 1)) % kMod;
      revHash = (revHash + (currChar - 'a' + 1) * powVal) % kMod;
      powVal = (powVal * hashBase) % kMod;

      if (forwHash == revHash)
        index = i;
    }

    string suffix = s.substr(index + 1);
    string revSuffix(suffix.rbegin(), suffix.rend());

    return revSuffix + s;
  }
};