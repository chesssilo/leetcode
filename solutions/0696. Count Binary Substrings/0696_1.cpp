class Solution {
public:
  int countBinarySubstrings(const string &s) {
    int count = 0;
	  int j, k = 0;
    for (int i = 0; i < ((int)s.length()-1); i++) {
      if (s[i] != s[i + 1]) {
        j = i;
			  k = i + 1;
			  char temp = s[k];
        while (j >= 0 && k < (int)s.length()) {
          if (s[j] != s[k] && (s[k] == temp)) {
            count++;
					  j--;
					  k++;
          } else {
            break;
          }
        }
      }
    }
    return count;
  }
};