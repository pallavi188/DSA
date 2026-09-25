class Solution {
public:
    void f(int idx,vector<int>&list,vector<vector<int>>&ans,vector<int>&nums){
        int n = nums.size();
        if(idx == n){
            ans.push_back(list);
            return;
        }
        //pick
        list.push_back(nums[idx]);
        f(idx+1,list,ans,nums);
        list.pop_back();
        //handle duplicate cases
        int i = idx+1;
        while(i<n && nums[i] == nums[i-1])i++;
        f(i,list,ans,nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       vector<int>list;
       vector<vector<int>>ans;
       sort(nums.begin(),nums.end());
       f(0,list,ans,nums);
       return ans;
    }
};