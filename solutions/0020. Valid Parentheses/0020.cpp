// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
	bool isValid(const string &s) {
		stack <char, vector<char>> st;
		
		for (char c : s) {
			if (c == '(') {
				st.push(')');
			} else if (c == '{') {
				st.push('}');
			} else if (c == '[') {
				st.push(']');
			} else {
				if (st.empty() || st.top() != c) {
					return false;
				}
				st.pop();
			}
		}
		return st.empty();
	}
};