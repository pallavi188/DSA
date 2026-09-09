class Solution {
public:
    int f(int idx,vector<int>&arr,int k,vector<int>&dp){
        int n = arr.size();
        //base case
        if(idx == n) return 0;
        int maxSum = 0;
        int len =0,maxi = 0;
        if(dp[idx] != -1) return dp[idx];
        for(int j=idx;j < min(n,idx+k);j++){
            len++;
            maxi = max(maxi,arr[j]);
            int sum = (len * maxi) + f(j+1,arr,k,dp);
            maxSum = max(maxSum, sum);
        }
        return dp[idx] = maxSum;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n,-1);
        return f(0,arr,k,dp);
    }
};