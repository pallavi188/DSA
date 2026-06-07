class Solution {
public:
    int f(int idx,int n,vector<int>&arr,vector<vector<int>>&dp){
        if(idx == 0){
           if(n%arr[0] == 0)return n/arr[0];
           else
           return 1e9; 
        }
        if(dp[idx][n] != -1) return dp[idx][n];
        int not_pick = f(idx-1,n,arr,dp);
        int pick = 1e9;
        if(arr[idx]<=n)
        pick = 1+f(idx,n-arr[idx],arr,dp);
        return dp[idx][n] = min(pick,not_pick);
    }
    int numSquares(int n) {
        vector<int>arr;
        for(int i=1;i*i<=n;i++){
            arr.push_back(i*i);
        }
        int num = arr.size();
        vector<vector<int>>dp(num,vector<int>(n+1,-1));
        return f(num-1,n,arr,dp);
    }
};