class Solution {
public:
    int f(int idx,int tar,vector<int>&stones,vector<vector<int>>&dp){
        if(idx == 0){
            if(stones[0]<=tar) return stones[0];
            else 
            return 0;
        }
        if(dp[idx][tar] != -1) return dp[idx][tar];
        int not_pick = f(idx-1,tar,stones,dp);
        int pick = 0;
        if(stones[idx] <= tar){
            pick += stones[idx] + f(idx-1,tar-stones[idx],stones,dp);
        }
        return dp[idx][tar] = max(pick,not_pick);
    }
    int lastStoneWeightII(vector<int>& stones) {
        int S = 0;
        int n = stones.size();
        for(int i=0;i<n;i++){
             S += stones[i];
        }
        int tar = S/2;
        vector<vector<int>>dp(n+1,vector<int>(tar+1,-1));
        return S -  2*f(n-1,tar,stones,dp);
    }
};