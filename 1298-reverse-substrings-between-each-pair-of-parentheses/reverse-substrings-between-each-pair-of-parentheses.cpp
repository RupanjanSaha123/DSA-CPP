class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        string curr = "";

        for (char ch : s) {

            if (ch == '(') {
                // Save the string built so far
                st.push(curr);
                curr = "";
            }
            else if (ch == ')') {
                // Reverse the current innermost substring
                reverse(curr.begin(), curr.end());

                // Attach it to the string before '('
                curr = st.top() + curr;
                st.pop();
            }
            else {
                curr += ch;
            }
        }

        return curr;
    }
};