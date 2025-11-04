class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int n = nums.size();
        if(n==2)return -1;
        int ans=-1;
        sort(nums.begin(),nums.end());
        int mini = nums[0],maxi = nums[n-1];
        for(int i=1;i<n-1;i++){
            if(nums[i]!=mini && nums[i] != maxi){
                ans = nums[i];
                break;
            }
        }
        return ans;
    }
};