# Time complexity: O(1)
# Space complexity: O(1)
values = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
    numerals = ["M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]

    result = ""
    for i in range(len(values)):
        while num >= values[i]:
            num -= values[i]
            result += numerals[i]

    return result