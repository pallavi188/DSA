class Solution {
public:
    void f(int idx,vector<int>&list,vector<vector<int>>&ans,vector<int>&cand,int target){
        if(idx==cand.size()){
            if(target == 0){
                ans.push_back(list);
            }
            return;
        }
        //pick 
        if(cand[idx] <= target){
            list.push_back(cand[idx]);
            f(idx,list,ans,cand,target-cand[idx]);
            list.pop_back();
        }
        //not pick
        f(idx+1,list,ans,cand,target);
    }
    vector<vector<int>> combinationSum(vector<int>& cand, int target) {
       vector<int>list;
       vector<vector<int>>ans;
       f(0,list,ans,cand,target);
       return ans;
    }
};