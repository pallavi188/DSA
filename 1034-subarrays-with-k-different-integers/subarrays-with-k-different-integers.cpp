class Solution {
public:
    int f(vector<int>&nums,int k){
        if(k<0)return 0;

        int l =0,r=0,cnt=0;
        unordered_map<int,int>mp;
        while(r<nums.size()){
            mp[nums[r]]++;
            while(mp.size()>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0)
                mp.erase(nums[l]);
                l = l+1;
            }
            cnt=cnt+(r-l+1);
            r++;
        }
        return cnt;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
       return f(nums,k)-f(nums,k-1);
    }
};