// Time complexity: O(n)
// Space complexity: O(1)
class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> result;
        int i = 1;
        while (i <= n) {
            string word;
            if (i % 3 == 0) word += "Fizz";
            if (i % 5 == 0) word += "Buzz";

            result.push_back(word.empty() ? to_string(i) : word);
            i++;
        }
        return result;
    }
};