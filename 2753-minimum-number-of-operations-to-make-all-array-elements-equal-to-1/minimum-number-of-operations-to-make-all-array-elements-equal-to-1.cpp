class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int g = nums[0];
        for (int x : nums) g = gcd(g, x);
        if (g > 1) return -1;

        int ones = count(nums.begin(), nums.end(), 1);
        if (ones > 0) return n - ones;

        int ans = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int g = nums[i];
            for (int j = i + 1; j < n; ++j) {
                g = gcd(g, nums[j]);
                if (g == 1) {
                    ans = min(ans, j - i);
                    break;
                }
            }
        }

        return ans + n - 1;
    }
};