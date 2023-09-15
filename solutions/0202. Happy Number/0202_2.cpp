// Time complexity: O(logn)
// Space complexity: O(1)
class Solution {
public:
    bool isHappy(int n) {
        int slow = n;
        int fast = n;

        while(true) {
            slow = next(slow);
            fast = next(next(fast));
            if (fast == 1) {
                return true;
            }
            if (fast == slow) {
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