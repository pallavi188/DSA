class Solution {
public:
    int f(vector<int>& nums, int idx, int rem, vector<vector<int>>& dp) {
        if (idx == nums.size()) {
            if (rem == 0) return 0;        // valid: no more to add
            return INT_MIN;               // invalid
        }

        if (dp[idx][rem] != -1) return dp[idx][rem];

        // take current element: add its value + best from rest with updated remainder
        int newRem = (rem + nums[idx] % 3) % 3;
        int take = f(nums, idx + 1, newRem, dp);
        if (take != INT_MIN) take += nums[idx];

        // skip current
        int skip = f(nums, idx + 1, rem, dp);

        return dp[idx][rem] = max(take, skip);
    }

    int maxSumDivThree(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(3, -1));
        int ans = f(nums, 0, 0, dp);
        return ans < 0 ? 0 : ans;
    }
};
