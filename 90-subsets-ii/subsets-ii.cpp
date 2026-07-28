class Solution {
public:
    void printSubset(vector<int>&nums,vector<int>&ans,
    vector<vector<int>>&result,int idx){
        int n = nums.size();
        if(idx == nums.size()){
            result.push_back(ans);
            return;
        }
        ans.push_back(nums[idx]);
        printSubset(nums,ans,result,idx+1);
        ans.pop_back();
        
        int i = idx+1;
        while(i<n && nums[i]==nums[i-1])i++;
        printSubset(nums,ans,result,i);
    
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
       vector<int>ans;
        vector<vector<int>>result;
        sort(nums.begin(),nums.end());
        printSubset(nums,ans,result,0);
        return result;
    }
};