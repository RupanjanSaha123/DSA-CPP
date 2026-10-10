
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        long long k = (long long)k1 + k2;
        vector<long long> freq(100001, 0);

        long long total = 0;

        for (int i = 0; i < nums1.size(); i++) {
            int d = abs(nums1[i] - nums2[i]);
            freq[d]++;
            total += d;
        }

        if (total <= k) return 0;

        for (int d = 100000; d > 0 && k > 0; d--) {
            if (freq[d] == 0) continue;

            long long move = min(k, freq[d]);

            freq[d] -= move;
            freq[d - 1] += move;
            k -= move;
        }

        long long ans = 0;

        for (int d = 0; d <= 100000; d++) {
            ans += freq[d] * d * d;
        }

        return ans;
    }
};
