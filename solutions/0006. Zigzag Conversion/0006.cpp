// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    string convert(const string& s, int numRows) {
        if (s.empty())
            return "";
        if (s.length() == 1)
            return s;
        if (numRows == 1)
            return s;

        string ans;
        vector<string> rows(min(numRows, int(s.length())));
        int currRow = 0;
        bool goDown = false;

        for (const char c : s) {
            rows[currRow] += c;
            if (currRow == 0 || currRow == numRows - 1)
                goDown = !goDown;
            currRow += goDown ? 1: -1;    
        }
        for (string_view row : rows)
            ans += row;

        return ans;             
    }
};