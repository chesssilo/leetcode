// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
	string reverseOnlyLetters(string &s) {
		for (int i = 0, j = s.length() - 1; i < j; ++i, --j) {
			while (i < j && !isLetter(s[i]))
				++i;
			while (i < j && !isLetter(s[j]))
				--j;
			swap(s[i], s[j]);
		}
		return s;
	}
	
private:
	bool isLetter(char c) {
		return ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z');
	}
};