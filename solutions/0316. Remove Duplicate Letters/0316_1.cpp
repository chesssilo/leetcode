// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> frequency;
        unordered_set<char> visited;
        stack<char> result;

    
        for (char c : s) {
            frequency[c]++;
        }

        for (char c : s) {
            frequency[c]--;

            if (visited.find(c) != visited.end()) {
                continue;
            }

            while (!result.empty() && c < result.top() && frequency[result.top()] > 0) {
                visited.erase(result.top());
                result.pop();
            }

            result.push(c);
            visited.insert(c);
        }

        string finalResult = "";
        while (!result.empty()) {
            finalResult = result.top() + finalResult;
            result.pop();
        }

        return finalResult;
    }
};