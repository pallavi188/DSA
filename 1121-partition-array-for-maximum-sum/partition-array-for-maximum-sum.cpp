class Solution {
public:
   
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>dp(n+1,0);
        int maxSum = INT_MIN;
        for(int idx=n-1;idx>=0;idx--){
            int maxi =INT_MIN,len = 0;
            for(int j=idx;j<min(idx+k,n);j++){
                len++;
                maxi = max(maxi,arr[j]);
                int sum = (len * maxi) + dp[j+1];
                maxSum = max(maxSum,sum);
            }
            dp[idx] = maxSum;
        }
        return dp[0];
    }
};