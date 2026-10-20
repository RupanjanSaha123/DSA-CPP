
class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> sortedNums = nums;
        sort(sortedNums.begin(), sortedNums.end());

        int ans = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool valid = true;

            for (int start = 0; start < n && valid; start += k) {
                int descents = 0;

                for (int i = start; i < start + k - 1; i++) {
                    if (nums[i] > nums[i + 1]) {
                        descents++;
                    }
                }

                // A sequence is a rotation of a sorted
                // sequence if it has at most one descent,
                // including the circular boundary.
                if (k > 1 && nums[start + k - 1] > nums[start]) {
                    descents++;
                }

                if (descents > 1) {
                    valid = false;
                    break;
                }

                // Also verify that this block contains
                // exactly the values in its sorted segment.
                vector<int> a(nums.begin() + start,
                              nums.begin() + start + k);
                vector<int> b(sortedNums.begin() + start,
                              sortedNums.begin() + start + k);

                sort(a.begin(), a.end());

                if (a != b) valid = false;
            }

            if (valid) ans += k;
        }

        return ans;
    }
};
