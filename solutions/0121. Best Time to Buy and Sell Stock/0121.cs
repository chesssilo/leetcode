// Time complexity: O(n)
// Space complexity: O(1)
public class Solution {
    public int MaxProfit(int[] prices) {
        int max = 0;
        int min = prices[0];

        foreach(int price in prices) {
            if(price < min) {
                min = price;
            }
            max = Math.Max(max, price - min);
        }
        return max;
    }
}