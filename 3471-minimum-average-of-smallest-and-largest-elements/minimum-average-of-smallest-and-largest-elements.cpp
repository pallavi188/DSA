class Solution {
public:
    double minimumAverage(vector<int>& nums) {
       
        int n = nums.size();
        double ans = 1e18; 

        sort(nums.begin(),nums.end());

        for(int i=0;i<n/2;i++){
            double avg = (nums[i]+nums[n-1-i])/2.0 ;
            ans = min(ans,avg);
        }
      
        return ans;
    }
};