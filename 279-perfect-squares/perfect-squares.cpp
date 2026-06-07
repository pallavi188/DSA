class Solution {
public:
  
    int numSquares(int n) {
        vector<int>arr;
        for(int i=1;i*i<=n;i++){
            arr.push_back(i*i);
        }
        int num = arr.size();
        vector<vector<int>>dp(num,vector<int>(n+1,0));
        for(int i=0;i<=n;i++){
            if(i%arr[0]==0)dp[0][i] = i/arr[0];
            else
            dp[0][i] = 1e9;
        }
        for(int idx=1;idx<num;idx++){
            for(int i=0;i<=n;i++){
                int not_pick = dp[idx-1][i];
                int pick = 1e9;
                if(arr[idx]<=i)
                pick = 1 + dp[idx][i-arr[idx]];

                dp[idx][i] = min(pick,not_pick);
            }
        }
        return dp[num-1][n];
    }
};