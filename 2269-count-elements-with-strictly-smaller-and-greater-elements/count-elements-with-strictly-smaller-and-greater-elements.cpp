class Solution {
public:
    int countElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        if (n < 3)
            return 0;
        int mn = nums[0], mx = nums[n - 1];
        int cntmn = 0, cntmx = 0;
        for (int x : nums) {
            if (x == mn)
                cntmn++;
            else
                break;
        }
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] == mx)
                cntmx++;
            else
                break;
        }
        int ans = n - cntmn - cntmx;
        return max(ans, 0);
    }
};