class Solution {
public:
    int mod = 1e9+7;
    vector<vector<int>>directions{{-1,0},{0,-1},{-1,-1}};
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        vector<vector<pair<int,int>>>dp(n,vector<pair<int,int>>(n,{-1,0}));
        dp[n-1][n-1] = {0,1};
        int dr[] = {1,0,1};
        int dc[] = {0,1,1};
        for(int r=n-1;r>=0;--r){
            for(int c=n-1;c>=0;--c){
                if(r==n-1 && c==n-1)continue;
                if(board[r][c]=='X')continue;
                int max_s = -1;
                int path_cnt=0;
                for(int i=0;i<3;++i){
                    int nr = r+dr[i];
                    int nc = c+dc[i];
                    if(nr<n && nc<n && dp[nr][nc].first != -1){
                        int curr_src = dp[nr][nc].first;
                        if(curr_src > max_s){
                            max_s = curr_src;
                            path_cnt = dp[nr][nc].second;
                        }else if(curr_src == max_s){
                            path_cnt = (path_cnt+dp[nr][nc].second)%mod;
                        }
                    }
                }
                if(max_s != -1){
                    int cell_val =(board[r][c] == 'E')?0:(board[r][c]-'0');
                    dp[r][c] = {max_s + cell_val,path_cnt};
                }
            }
        }
        if(dp[0][0].first==-1){
            return {0,0};
        }
        return {dp[0][0].first,dp[0][0].second};
    }
};