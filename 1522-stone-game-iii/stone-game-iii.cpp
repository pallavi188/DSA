class Solution {
public:
    string stoneGameIII(vector<int>& sv) {
        int n = sv.size();
        vector<int>dp(n+1,0);

        for(int idx=n-1;idx>=0;idx--){
            int res = -1e9;
            res = max(res,sv[idx] - dp[idx+1]);
            if(idx+1<n) res = max(res,sv[idx]+sv[idx+1]-dp[idx+2]);
            if(idx+2<n) res = max(res,sv[idx]+sv[idx+1]+sv[idx+2]-dp[idx+3]);
            dp[idx] = res;
        }         
        if(dp[0]>0) return "Alice";
        else if(dp[0]<0) return "Bob";
        else
        return "Tie";
    }
};