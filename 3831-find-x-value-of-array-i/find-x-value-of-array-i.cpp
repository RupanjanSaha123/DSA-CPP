class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
          vector<long long> result(k, 0);
        vector<long long> dp(k, 0);

        for (long long num : nums) {
            vector<long long> ndp(k, 0);

            int x = num % k;

            // Start a new subarray containing only nums[i]
            ndp[x]++;

            // Extend all previous subarrays
            for (int r = 0; r < k; r++) {
                int newRemainder = (r * x) % k;
                ndp[newRemainder] += dp[r];
            }

            // Every subarray ending here contributes to the answer
            for (int r = 0; r < k; r++) {
                result[r] += ndp[r];
            }

            dp = ndp;
        }

        return result;
    }
};