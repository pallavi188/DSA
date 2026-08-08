class Solution {
public:
    void f(int idx,vector<int>&list,vector<vector<int>>&ans,vector<int>&cand,int target){
       if(target == 0){
        ans.push_back(list);
        return;
       }
       for(int i=idx;i<cand.size();i++){
        if(i>idx && cand[i]==cand[i-1]) continue;
        if(cand[i] > target) break;
        list.push_back(cand[i]);
        f(i+1,list,ans,cand,target - cand[i]);
        list.pop_back();
       }
    }
    vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
        sort(cand.begin(),cand.end());
        vector<int>list;
        vector<vector<int>>ans;
        f(0,list,ans,cand,target);
        return ans;
    }
};