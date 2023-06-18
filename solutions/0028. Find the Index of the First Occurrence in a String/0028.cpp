class Solution {
public:
    int strStr(string haystack, string needle) {

        auto pos = haystack.find(needle);
        if (pos != string::npos)
            return pos;
        else
            return -1;
    }
};