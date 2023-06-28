// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
	string reverseOnlyLetters(const string &s) {
		string res = s;
		int dst = (int)res.size() - 1;
		for (int src = 0; src < (int)s.size(); src++) {
			if (isLetter(s[src])) {
				while(!isLetter(res[dst])) {
					dst--;
					assert(dst >= 0);
				}
				res[dst] = s[src];
				dst--;
			}	
		}
		return res;	
	}
	
private:	
	bool isLetter(char c) {
		return ('A' <= c && c <= 'Z') || ('a' <= c && c <= 'z');
	}
};				