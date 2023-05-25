#include <iostream>
#include <stack>
#include <string>

class Solution {
public:
	bool isValid(std::string s)
	{
		std::stack <char> stk;
		int length = s.length();
		char top;

		for (int i = 0; i < length; i++) {
			if (s[i] == '(' || s[i] == '{' || s[i] == '[')
				stk.push(s[i]);

			else {
				if (stk.empty())
					return false;

				else {
					top = stk.top();
					if (s[i] == ')' && top == '(' || s[i] == '}' && top == '{' || s[i] == ']' && top == '[')
						stk.pop();

					else return false;
				}
			}
		}

		if (stk.empty()) return true;

		else return false;
	}
};

int main() {
	Solution solution;

	std::string s;
	std::cin >> s;

	bool b = solution.isValid(s);
	std::cout << b << std::endl;

	return 0;
}