// Time complexity: O(nlogn)
// Space complexity: O(n)
class Solution {
public:
    int maximumLength(vector<int>& nums) {
        long long ans = 0;
        map<int, int> freq;
        for (auto num : nums)
            ++freq[num];
        for (auto [num, count] : freq) {
            long long curNum = num;
            long long seqLen = 0;
            if (curNum == 1) {
                seqLen += freq[curNum];
                freq[curNum] = 0;
            }
            while (curNum < INT_MAX && freq[curNum] > 0) {
                seqLen += 2;
                if (freq[curNum] == 1)
                    break;
                freq[curNum] = 0;
                curNum = curNum * curNum;    
            }
            if (seqLen % 2 == 0)
                --seqLen;
            ans = max(ans, seqLen);    
        }

        return ans;
    }
};