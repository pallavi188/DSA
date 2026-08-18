class Solution {
public:
    void dfs(int sr,int sc,vector<vector<int>>&ans,vector<vector<int>>&image,
    int color,int initialcolor){
         ans[sr][sc] = color;
         int n = image.size();
         int m = image[0].size();
         int dr[] = {-1,1,0,0};
         int dc[] = {0,0,1,-1};
         for(int i=0;i<4;i++){
            int newRow = sr + dr[i];
            int newCol = sc + dc[i];
            if(newRow>=0 && newRow<n && newCol>=0 && newCol < m && ans[newRow][newCol] != color && image[newRow][newCol] == initialcolor){
                dfs(newRow,newCol,ans,image,color,initialcolor);
            }
         }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size();
        int m = image[0].size();
       int initialColor = image[sr][sc];
       vector<vector<int>>ans = image;
       dfs(sr,sc,ans,image,color,initialColor);
       return ans;
    }
};