using System;

namespace sad
{
    public class Solution
    {
        public int RomanToInt(string s)
        {
            int n = s.Length;
            if (n == 0)
            {
                return 0;
            }

            int result = 0;

            for (int i = 0; i < n; i++)
            {
                switch (s[i])
                {
                    case 'I':
                        result += 1;
                        break;
                    case 'V':
                        result += 5;
                        break;
                    case 'X':
                        result += 10;
                        break;
                    case 'L':
                        result += 50;
                        break;
                    case 'C':
                        result += 100;
                        break;
                    case 'D':
                        result += 500;
                        break;
                    case 'M':
                        result += 1000;
                        break;
                }
            }

            for (int i = 1; i < n; i++)
            {
                if ((s[i] == 'V' || s[i] == 'X') && s[i - 1] == 'I')
                {
                    result -= 1 + 1;
                }

                if ((s[i] == 'L' || s[i] == 'C') && s[i - 1] == 'X')
                {
                    result -= 10 + 10;
                }

                if ((s[i] == 'D' || s[i] == 'M') && s[i - 1] == 'C')
                {
                    result -= 100 + 100;
                }
            }
            return result;
        }
    }

    internal class Program
    {
        static void Main(string[] args)
        {
            string sss = Console.ReadLine();
            Solution s = new Solution();
            int che = s.RomanToInt(sss);
            Console.WriteLine(che);
        }
    }
}