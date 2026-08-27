class Solution {
public:
    
    int superEggDrop(int e, int f) {
        vector<vector<int>>dp(e+1,vector<int>(f+1,0));
        for(int eg=0;eg<=e;eg++){
            dp[eg][0] = 0;
            dp[eg][1] = 1;
        }
        for(int fl=2;fl<=f;fl++){
            dp[1][fl]=fl;
        }
      
        for(int eg=2;eg<=e;eg++){
            for(int fl = 2;fl<=f;fl++){
                  dp[eg][fl] = INT_MAX;
                  int low =1,high = fl;
                  while(low <= high){
                    int mid = low + (high-low)/2;
                    int breaks = dp[eg-1][mid-1];
                    int notBreak = dp[eg][fl-mid];
                    int worst = 1 + max(breaks,notBreak);
                    dp[eg][fl] = min(dp[eg][fl],worst);
                    if(breaks < notBreak) low = mid+1;
                    else
                    high = mid-1;
                  }
            }
        }
        return dp[e][f];
    }
};