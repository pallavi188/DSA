class Solution {
public:
    int n,m;
    vector<vector<int>>directions{{-1,0},{1,0},{0,1},{0,-1}};
    void dfs(int row,int col,vector<vector<int>>&ans,vector<vector<int>>&image,int newColor,int initialColor){
        ans[row][col] = newColor;
        for(vector<int>&dir : directions){
            int new_row = row + dir[0];
            int new_col = col + dir[1];
            if(new_row>=0 && new_row<n && new_col>=0&&new_col<m && ans[new_row][new_col] != newColor && image[new_row][new_col]==initialColor){
                dfs(new_row,new_col,ans,image,newColor,initialColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        n = image.size();
        m = image[0].size();
       int initialColor = image[sr][sc];
       vector<vector<int>>ans = image;
       dfs(sr,sc,ans,image,color,initialColor);
       return ans;
    }
};