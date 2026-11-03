class Solution {
public:
    int minMoves(vector<int>& nums) {
        int total_sum = 0;
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int maxi = nums[n-1];
        for(int i=0;i<n;i++){
            total_sum += maxi - nums[i];
        }
        return total_sum;
    }
};