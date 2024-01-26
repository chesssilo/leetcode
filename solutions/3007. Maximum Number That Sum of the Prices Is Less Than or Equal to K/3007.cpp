// Time complexity: O(log(10^5))
// Space complexity: O(1)
typedef long long ll;

class Solution {
public:
    ll findMaximumNumber(ll k, int x) {
        ll left = 1;
        ll right = 1e15;

        while (left < right) {
            ll mid = (left + right + 1) / 2;
            if (getSumPrices(mid, x) > k)
                right = mid - 1;
            else 
                left = mid;    
        }

        return left;
    }

private:
    ll getSumPrices(ll num, int x) {
        ll sumPrices = 0;
        ++num;

        for (int i = leftmostColumnIndex(num); i > 0; --i)
            if (i % x == 0) {
                const ll groupSize = 1LL << i;
                const ll halfGroupSize = 1LL << i - 1;
                sumPrices += num / groupSize * halfGroupSize;
                sumPrices += max(0LL, (num % groupSize) - halfGroupSize);
            }

        return sumPrices;    
    }

    int leftmostColumnIndex(ll num) {
        return 63 - __builtin_clzll(num) + 1;
    }
};