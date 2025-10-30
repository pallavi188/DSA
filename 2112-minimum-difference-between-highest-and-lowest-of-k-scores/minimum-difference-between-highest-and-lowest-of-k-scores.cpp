class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans = INT_MAX;
        //sliding window
        for(int i=0;i+k-1<nums.size();i++){
            ans = min(ans,nums[i+k-1]-nums[i]); 
        }
        return ans;
    }
};