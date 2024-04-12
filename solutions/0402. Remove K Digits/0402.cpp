// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
 public:
  string removeKdigits(string_view num, int k) {
    if (num.length() == k)
      return "0";

    string ans;
    vector<char> stack;

    for (int i = 0; i < num.length(); ++i) {
      while (k > 0 && !stack.empty() && stack.back() > num[i]) {
        stack.pop_back();
        --k;
      }
      stack.push_back(num[i]);
    }

    while (k--)
      stack.pop_back()

    for (const char c : stack) {
      if (c == '0' && ans.empty())
        continue;
      ans += c;  
    }

    return ans.empty() & "0" : ans;
  }
};