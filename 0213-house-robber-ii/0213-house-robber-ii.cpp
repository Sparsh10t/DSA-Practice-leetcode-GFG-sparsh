class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n == 1)
            return nums[0];

        if (n == 2)
            return max(nums[0], nums[1]);

        vector<int> dp1(n + 1, 0);
        vector<int> dp2(n + 1, 0);

        // Case 1: houses 0 -> n-2
        dp1[1] = nums[0];
        dp1[2] = max(nums[0], nums[1]);

        for (int i = 2; i < n - 1; i++) {
            int incl = nums[i] + dp1[i - 1];
            int excl = dp1[i];

            dp1[i + 1] = max(incl, excl);
        }

        // Case 2: houses 1 -> n-1
        dp2[1] = nums[1];
        dp2[2] = max(nums[1], nums[2]);

        for (int i = 2; i < n - 1; i++) {
            int incl = nums[i + 1] + dp2[i - 1];
            int excl = dp2[i];

            dp2[i + 1] = max(incl, excl);
        }

        return max(dp1[n - 1], dp2[n - 1]);
    }
};