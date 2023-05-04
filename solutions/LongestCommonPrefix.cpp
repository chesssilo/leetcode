#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
	std::string longestCommonPrefix(std::vector<std::string>& strs) {

		int sizeStrs = strs.size();
		std::string coincidences;

		if (sizeStrs == 0)
			return "";

		if (sizeStrs == 1)
			coincidences += strs[0];

		std::sort(begin(strs), end(strs));

		std::string first = strs[0];
		std::string last = strs[sizeStrs - 1];


		for (int i = 0; i < first.size(); i++) {
			if (first[i] == last[i])
				coincidences += first[i];

			else break;
		}
		return coincidences;
	}
};

int main() {
	std::vector<std::string> strs = { "flower","flow","flight" };

	Solution solution;
	solution.longestCommonPrefix(strs);

	return 0;
}