class Solution {
public:
    void f(int idx,vector<int>&list,vector<vector<int>>&result,
           vector<int>&cand,int target){
        int n = cand.size();
        if(idx == n){
            if(target==0){
                result.push_back(list);
            }
            return;
        }
        //not pick
         f(idx+1,list,result,cand,target);
        //pick
        if(cand[idx]<= target){
            list.push_back(cand[idx]);
            f(idx,list,result,cand,target-cand[idx]);
            list.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& cand, int target) {
         vector<vector<int>>result;
         vector<int>list;
         f(0,list,result,cand,target);
         return result;
    }
};