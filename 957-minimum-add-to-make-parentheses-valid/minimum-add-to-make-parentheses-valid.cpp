class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0;
        int ans = 0;

        for (char ch : s) {

            if (ch == '(') {
                open++;
            }
            else {
                // We have an '(' to match this ')'
                if (open > 0) {
                    open--;
                }
                else {
                    // No '(' available, so insert one
                    ans++;
                }
            }
        }

        // Remaining '(' need matching ')'
        ans += open;

        return ans;
    }
};