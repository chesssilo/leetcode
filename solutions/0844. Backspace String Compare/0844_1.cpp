// Time complexity: O(∣s∣+∣t∣)
// Space complexity: O(∣s∣+∣t∣)
class Solution {
public:
    bool backspaceCompare(const string &s, const string &t) {
        return norm(s) == norm(t);
    }
private:
    string norm(const string& s) {
        string stack;
        for (const char c : s)
        if (c != '#')
            stack.push_back(c);
        else if (!stack.empty())
            stack.pop_back();
        return stack;
    }    
};