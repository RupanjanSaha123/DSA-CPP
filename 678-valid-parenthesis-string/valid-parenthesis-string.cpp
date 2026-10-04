class Solution {
public:
    bool checkValidString(string s) {
        int low = 0;   // Minimum possible unmatched '('
        int high = 0;  // Maximum possible unmatched '('

        for (char ch : s) {

            if (ch == '(') {
                low++;
                high++;
            }

            else if (ch == ')') {
                low--;
                high--;
            }

            else { // '*'
                // '*' can be ')' or '(' or empty
                low--;   // Treat '*' as ')'
                high++;  // Treat '*' as '('
            }

            // We can never have negative possible minimum
            if (high < 0)
                return false;

            // low cannot actually be negative
            if (low < 0)
                low = 0;
        }

        // If zero unmatched '(' is possible, string is valid
        return low == 0;
    }
};