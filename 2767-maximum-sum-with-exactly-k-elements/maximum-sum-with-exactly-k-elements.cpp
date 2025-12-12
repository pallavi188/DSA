class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int sum =0;
        for(int i=0;i<k;i++){
            sum += nums[n-1];
            nums[n-1]=nums[n-1]+1;
        }
        return sum;
    }
};