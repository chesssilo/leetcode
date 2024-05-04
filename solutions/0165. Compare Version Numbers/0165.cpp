// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
 public:
  int compareVersion(string_view version1, string_view version2) {
    const int n1 = version1.length();
    const int n2 = version2.length();
    int v1 = 0;
    int v2 = 0;

    for (int i = 0, j = 0; i < n1 || j < n2; ++i, ++j) {
      while (i < n1 && version1[i] != '.')
        v1 = 10 * v1 + (version1[i++] - '0');
      while (j < n2 && version2[j] != '.')
        v2 = 10 * v2 + (version2[j++] - '0');

      if (v1 < v2)
        return -1;
      else if (v1 > v2)
        return 1;
      v1 = 0;
      v2 = 0;
    }

    return 0;
  }
};