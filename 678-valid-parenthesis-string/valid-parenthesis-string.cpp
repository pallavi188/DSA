class Solution {
public:
    bool f(string s, int idx, int cnt, vector<vector<int>>& dp) {
        int n = s.length();
        if (cnt < 0)
            return false;
        if (idx == n) {
            return (cnt == 0);
        }
        if (dp[idx][cnt] != -1)
            return dp[idx][cnt];

        if (s[idx] == '(')
            return dp[idx][cnt] = f(s, idx + 1, cnt + 1, dp);
        else if (s[idx] == ')')
            return dp[idx][cnt] = f(s, idx + 1, cnt - 1, dp);
        else {
            return dp[idx][cnt] = f(s, idx + 1, cnt + 1, dp) |
                                  f(s, idx + 1, cnt - 1, dp) |
                                  f(s, idx + 1, cnt, dp);
        }
    }
    bool checkValidString(string s) {
        //       int cnt =0;
        //     int n = s.length();
        //   vector<vector<int>>dp(n,vector<int>(n,-1));
        // return f(s,0,0,dp);

        // non recurrsive solution i.e linear solution
        int n = s.length();
        int min = 0, max = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                min = min + 1;
                max = max + 1;
            } else if (s[i] == ')') {
                min = min - 1;
                max = max - 1;
            } else {
                min = min - 1;
                max = max + 1;
            }
             if(min<0) min =0;
        if(max<0) return false;
        }
       return (min==0);
    }
};