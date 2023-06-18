class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {

		int sizeStrs = strs.size();
		string coincidences;

		if (sizeStrs == 0)
			return "";

		if (sizeStrs == 1)
			coincidences += strs[0];

		sort(begin(strs), end(strs));

		string first = strs[0];
		string last = strs[sizeStrs - 1];


		for (int i = 0; i < first.size(); i++) {
			if (first[i] == last[i])
				coincidences += first[i];

			else break;
		}
		return coincidences;
	}
};