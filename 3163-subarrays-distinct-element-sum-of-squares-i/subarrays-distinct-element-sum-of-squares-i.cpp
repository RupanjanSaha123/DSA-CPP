
class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            vector<int> freq(101, 0);
            int distinct = 0;

            for (int j = i; j < n; j++) {
                if (freq[nums[j]] == 0) {
                    distinct++;
                }

                freq[nums[j]]++;

                ans += distinct * distinct;
            }
        }

        return ans;
    }
};
