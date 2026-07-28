class Solution {
public:
    bool dfs(int r,int c,int idx,vector<vector<bool>>&vis,vector<vector<char>>&board,string word){
        if(idx == word.length()) return true;
        int n = board.size();
        int m = board[0].size();
        if(r<0 || r>=n|| c<0 || c>=m || vis[r][c] || board[r][c] != word[idx])
        return false;
        
        vis[r][c] = true;
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,1,-1};
        for(int i=0;i<4;i++){
            int newRow = r + dr[i];
            int newCol = c + dc[i];
            if(dfs(newRow,newCol,idx+1,vis,board,word))return true;
            
        }
        vis[r][c] = false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dfs(i,j,0,vis,board,word))return true;
            }
        }
        return false;
    }
};