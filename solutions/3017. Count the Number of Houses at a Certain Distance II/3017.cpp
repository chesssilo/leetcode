// Time complexity: O(n)
// Space complexity: O(n)
class Solution {
public:
    vector<long long> countOfPairs(int n, int x, int y) {
        if (x > y)
            swap(x, y);

        const int ringLen = y - x + 1;
        const int leftLineLen = x - 1;
        const int rightLineLen = n - y;

        vector<long long> ans(n);

        ans = addVectors(ans, bothInRing(n, ringLen));
        ans = addVectors(ans, bothInTheSameLine(n, leftLineLen));
        ans = addVectors(ans, bothInTheSameLine(n, rightLineLen));
        ans = addVectors(ans, lineToRing(n, leftLineLen, ringLen));
        ans = addVectors(ans, lineToRing(n, rightLineLen, ringLen));
        ans = addVectors(ans, lineToLine(n, x, y, leftLineLen, rightLineLen));
        for (long long& freq : ans)
            freq *= 2;

        return ans;      
    }
private:
    vector<long long> bothInRing(int n, int ringLen) {
        vector<long long> res(n);
        for (int k = 1; k <= (ringLen - 1) / 2; ++k)
            res[k - 1] += ringLen;
        if (ringLen % 2 == 0)
            res[ringLen / 2 - 1] += ringLen / 2;

        return res;        
    }

    vector<long long> bothInTheSameLine(int n, int lineLen) {
        vector<long long> res(n);
        for ( int k = 1; k <= lineLen; ++k)
            res[k - 1] += lineLen - k;

        return res;    
    }

    vector<long long> lineToRing(int n, int lineLen, int ringLen) {
        vector<long long> res(n);
        for (int k = 1; k <= lineLen + ringLen; ++k) {
            const int maxInRingLen = min(k - 1, ringLen / 2);
            const int minInRingLen = max(0, k - lineLen);
            if (minInRingLen <= maxInRingLen) {
                res[k - 1] += (maxInRingLen - minInRingLen + 1) * 2;
                if (minInRingLen == 0)
                    res[k - 1] -= 1;
                if (maxInRingLen * 2 == ringLen)
                    res[k - 1] -= 1;
            }
        }

        return res;
    }

    vector<long long> lineToLine(int n, int x, int y, int leftLineLen, int rightLineLen) {
        vector<long long> res(n);
        for (int k = 1; k <= leftLineLen + rightLineLen + 2; ++k) {
            const int maxInLeft = min(leftLineLen, k - 1 - (x < y));
            const int minInLeft = max(1, k - rightLineLen - (x < y));
            if (minInLeft <= maxInLeft)
                res[k - 1] += maxInLeft - minInLeft + 1;                
        }

        return res;
    }

    vector<long long> addVectors(const vector<long long>& a,
                                const vector<long long>& b) {
        vector<long long> res(a.size());
        transform(a.begin(), a.end(), b.begin(), res.begin(), plus<int>());
        return res;
    };
};