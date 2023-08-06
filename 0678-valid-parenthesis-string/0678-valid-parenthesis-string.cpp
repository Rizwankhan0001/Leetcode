class Solution {
public:
    bool checkValidString(string s) {
    // Initialize two variables cmin and cmax to keep track of the minimum and maximum number of open parentheses
    int cmin = 0, cmax = 0;
    // Iterate through each character 'c' in the input string 's'
    for (char c : s) {
        // If the character is an open parenthesis '('
        if (c == '(')
            // Increment both cmax and cmin by 1 since we encountered an open parenthesis
            cmax++, cmin++;
        // If the character is a closing parenthesis ')'
        if (c == ')')
            // Decrement cmax by 1 since we encountered a closing parenthesis
            // Also, decrement cmin by 1 if it's greater than 0 (to represent a valid closing parenthesis for an open one)
            cmax--, cmin = max(cmin - 1, 0);
        // If the character is a wildcard '*'
        if (c == '*')
            // Increment cmax by 1 (since '*' can be treated as an open parenthesis or an empty character)
            // Also, decrement cmin by 1 if it's greater than 0 (to represent a valid closing parenthesis for an open one)
            cmax++, cmin = max(cmin - 1, 0);
        // Check if the current value of cmax is negative, if so, it means we have encountered more closing parentheses than open ones
        // In that case, return false, as the string is not valid
        if (cmax < 0) return false;
    }
    // After processing the whole string, if cmin is 0, it means all open parentheses have been matched with closing ones,
    // So, return true, otherwise, return false.
    return cmin == 0;
}

};
