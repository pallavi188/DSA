class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n = nums.size();
        int ans =0;
        for(auto &it : nums){
            mp[it]++;
        }
        for(auto &x : mp){
            if(x.second > 1) ans = x.first;
        }
        return ans;
    }
};