using System;

namespace ConsoleApp1
{
    public class Solution
    {
        public int[] TwoSum(int[] nums, int target)
        {
            int[] V = { };
            for (int i = 0; i < nums.Length; i++) 
            {
                for (int j = 0; j < nums.Length; j++)
                {
                    if (i != j)
                    {
                        if (nums[i] + nums[j] == target)
                        {
                            return new int[] { i, j };
                        }
                    }
                }
            }
            return V;
        }
    }

    internal class Program
    {
        static void Main(string[] args)
        {
            int[] nums = { 2, 7, 11, 15 };
            int target = 9;

            Solution s = new Solution();

            int[]sda = s.TwoSum(nums, target);

            foreach (var i in sda)
            {
                Console.WriteLine(i);
            }
        }
    }
}