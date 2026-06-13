class Solution {
public:
    int nextIdx(vector<vector<int>>&jobs,int l,int curJobEnd){
        int n = jobs.size();
        int r = n-1;
        int res = n+1;
        while(l <= r){
            int mid = l + (r-l)/2;
            if(jobs[mid][0] >= curJobEnd){
                res = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }
        return res;
    }
    int f(int idx,vector<vector<int>>&jobs,vector<int>&dp){
        int n = jobs.size();
        if(idx >= n)return 0;
        if(dp[idx] != -1) return dp[idx];
        int not_pick = f(idx+1,jobs,dp);
        int next = nextIdx(jobs,idx+1,jobs[idx][1]);
       
        int pick = jobs[idx][2] + f(next,jobs,dp);
        return dp[idx] = max(pick,not_pick);
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();
        vector<vector<int>>jobs;
        for(int i=0;i<n;i++){
            jobs.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(jobs.begin(),jobs.end());
        vector<int>dp(n+1,-1);
        return f(0,jobs,dp);
    }
};