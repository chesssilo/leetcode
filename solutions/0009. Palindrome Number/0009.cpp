class Solution {
public:
    bool isPalindrome(int x) {
        std::vector<int> v;
        int a;

        if (x < 0) 
            return false;
        else
            while (x > 0) {
                a = x % 10;
                v.push_back(a);
                x = x / 10;
            }

        for (int i = 0; i < v.size() / 2; i++) {
            if (v[i] != v[v.size() - i - 1])
                return false;
        }
        return true;
    }
};