class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int cnt = 0, x;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0) {
                x = nums[i];
                cnt++;
                for (int j = i; j < nums.size(); j++) {
                    nums[j] -= x;
                }
            }
        }
        return cnt;
    }
};