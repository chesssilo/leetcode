// Time complexity: O(min(n,m))
// Space complexity: O(1)
class Solution {
public:
    int uniquePaths(const int m,const int n) {
        return choose(n + m - 2, m - 1);
    }
private:
    int choose(int n, int k) {
        k = min(k, n - k);
        long long result = 1;
        for (int i = 1; i <= k; ++i) 
            result = result * (n - k + i) / i;
        
        return (int)result;
    }    
};