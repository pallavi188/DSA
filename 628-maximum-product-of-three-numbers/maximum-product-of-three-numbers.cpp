class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<>());
        int n = nums.size();
        long long result = (long long)nums[0]*nums[1]*nums[2];
        long long best_no = (long long)nums[0]*nums[n-1]*nums[n-2];
        return max(result,best_no);
    }
};