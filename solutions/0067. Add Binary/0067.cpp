class Solution {
public:
    string addBinary(string a, string b) {
        int temp = 0;
        string result = "";

        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        int i = 0, sum;
        while (i < a.size() || i < b.size()) {
            sum = temp;

            if (i < a.size()) sum += a[i] - '0';
            if (i < b.size()) sum += b[i] - '0';

            if (sum == 0) temp = 0, result += '0';
            else if (sum == 1) temp = 0, result += '1';
            else if (sum == 2) temp = 1, result += '0';
            else temp = 1, result += '1';

            i++;
        }

        if (temp == 1)  result += '1';

        reverse(result.begin(), result.end());
        return result;
    }
};