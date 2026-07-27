class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        int l , r,sum = 0;
        vector<vector<int>>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i > 0 && nums[i] == nums[i-1]) continue;
           l = i+1;
           r = n-1;
           while(l<r){
           sum = nums[i]+nums[l]+nums[r];
           if(sum == 0){
            vector<int>res = {nums[i],nums[l],nums[r]};
            ans.push_back(res);
            l++;
            r--;
            while(l < r && nums[l]==nums[l-1])l++;
            while(l < r && nums[r]==nums[r+1])r--;
           }else if(sum > 0) r--;
           else
           l++;
        }
        }
        return ans;
    }
};