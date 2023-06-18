class Solution {
public:
    string interpret(string command) {
        string result = "";
        for (int i = 0; i < command.length(); i++) {
            if (command[i] == 'G') result += command[i];
            if (command[i] == '(' && command[i + 1] == ')') result += 'o';
            if (command[i] == '(' && command[i + 1] == 'a') result += "al";
        }
        return result;
    }
};