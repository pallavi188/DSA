class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
    int totsum =0 ;
        for(int num:nums){
            totsum += num;
        }
        if(abs(target)>totsum) return 0;
        int s2 = (totsum - target)/2 ;
        if(totsum - target<0 || (totsum - target)%2 != 0) return 0;
        vector<int>prev(s2+1,0),curr(s2+1,0);

        prev[0] = 1;

        if(nums[0]<=s2) prev[nums[0]] += 1;

        for(int i=1;i<nums.size();i++){
            for(int sum = 0;sum<=s2;++sum){
                int not_pick = prev[sum];
               int pick =0;
                if(nums[i] <= sum) pick = prev[sum - nums[i]];
                curr[sum] = pick + not_pick;
            }
            prev = curr;
        }
        return prev[s2];
    }
};