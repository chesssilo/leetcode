// Time complexity: O(klogn)
// Space complexity: O(n)
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> visited;
        while(true) {
            if (n == 1) {
                return true;
            }
            visited.insert(n);
            n = next(n);
            if (visited.count(n)) {
                return false;
            }
        }
    }

private:
    int next(int n) {
        int sum = 0;
        while (n > 0) {
            int d = n % 10;
            n /= 10;
            sum += d * d;
        }
        return sum;
    }    
};