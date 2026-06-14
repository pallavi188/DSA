class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.length();
        vector<vector<int>>dp(n+1,vector<int>(2,0));
       
       for(int idx=n-1;idx>=0;idx--){
        for(int prev =0;prev<=1;prev++){
                 int flip = INT_MAX;
                 int not_flip = INT_MAX;
            if(s[idx] == '0'){
            if(prev == 0){
                flip = 1 + dp[idx+1][1];
                not_flip = dp[idx+1][0];
            }else{
                flip = 1 + dp[idx+1][1];
            }
        }//s[idx] == 1
        else{
            if(prev==1){
                not_flip = dp[idx+1][1];
            }else{
                flip = 1 + dp[idx+1][0];
                not_flip = dp[idx+1][1];
            }
        }
        dp[idx][prev] = min(flip,not_flip);
        }
       }
       return dp[0][0];
    }
};