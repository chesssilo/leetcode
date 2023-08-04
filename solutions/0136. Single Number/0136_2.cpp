class Solution {
public:
    static const int EQUAL_COUNT = 2;

    int singleNumber(vector<int>& nums) {
        const int INT_BIT_SIZE = sizeof(int) * 8;
        size_t countOnes[INT_BIT_SIZE] = {};
        for (unsigned int x : nums) {
            for (int bit = 0; bit < INT_BIT_SIZE; ++bit) {
                countOnes[bit] += x & 1;
                x >>= 1;
            }
        }

        unsigned int ans = 0;
        for (int bit = 0; bit < INT_BIT_SIZE; ++bit) {
            ans |= (unsigned int)(countOnes[bit] % EQUAL_COUNT) << bit;
        }
        return ans;
    }
};