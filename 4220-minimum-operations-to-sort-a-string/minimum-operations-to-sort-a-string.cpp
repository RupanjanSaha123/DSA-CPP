
class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        if (is_sorted(s.begin(), s.end()))
            return 0;

        if (n == 2)
            return -1;

        char mn = *min_element(s.begin(), s.end());
        char mx = *max_element(s.begin(), s.end());

        if (s[0] == mn || s[n - 1] == mx)
            return 1;

        if (s[0] == mx && s[n - 1] == mn) {
            // Three operations only when both endpoint
            // characters are unique extremes.
            int minCount = count(s.begin(), s.end(), mn);
            int maxCount = count(s.begin(), s.end(), mx);

            if (minCount == 1 && maxCount == 1)
                return 3;
        }

        return 2;
    }
};
