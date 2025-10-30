class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end(),greater<>());
        int first_pair_product = nums[0]*nums[1];
        int second_pair_product = nums[n-1]*nums[n-2];
        return first_pair_product - second_pair_product;
    }
};