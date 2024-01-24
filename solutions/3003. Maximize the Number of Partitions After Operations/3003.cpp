// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    int maxPartitionsAfterOperations(string_view s, int k) {
        unordered_map<long long, int> mem;
        return maxPartitionsAfterOperations(s, 0, true, 0, k , mem) + 1;   
    }

private:
    int maxPartitionsAfterOperations(string_view s, int i, bool canChange,
                                    int mask, int k,
                                    unordered_map<long long, int>& mem) { 
        if (i == s.length())
            return 0;

        long long key = static_cast<long long>(i) << 27 |
                        (canChange ? 1 : 0) << 26 | static_cast<long long>(mask);
        if (const auto it = mem.find(key); it != mem.end())
            return it->second;

        int res = getRes(s, i, canChange, mask, 1 <<(s[i] - 'a'), k, mem);

        if (canChange)
            for (int j = 0; j < 26; ++j)
                res = max(res, getRes(s, i, false, mask, 1 << j, k , mem));

        return mem[key] = res;           
                                    }
    int getRes(string_view s, int i, bool nextCanChange, int mask,              int newBit, int k, unordered_map<long long, int>& mem) {
        const int nextMask = mask | newBit;
        if (__builtin_popcount(nextMask) > k)
            return 1 + maxPartitionsAfterOperations(s, i + 1, nextCanChange, newBit, k, mem);

        return maxPartitionsAfterOperations(s, i + 1, nextCanChange, nextMask, k, mem); 
    }                                
};