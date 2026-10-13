class Solution {
public:
    void dfs(int sr,int sc,vector<vector<int>>&image,vector<vector<int>>&Grid,int color,int oldColor){
        Grid[sr][sc] = color;
        int n = image.size();
        int m = image[0].size();
        int dr[]= {-1,1,0,0};
        int dc[]= {0,0,1,-1};
        for(int i=0;i<4;i++){
            int new_sr = sr + dr[i];
            int new_sc = sc + dc[i];
            if(new_sr >= 0 && new_sr < n && new_sc >= 0 && new_sc < m && 
               image[new_sr][new_sc]== oldColor){
                dfs(new_sr,new_sc,image,Grid,color,oldColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
       vector<vector<int>>&Grid = image;
       int oldColor = image[sr][sc];
       if(color == oldColor)return image;
       dfs(sr,sc,image,Grid,color,oldColor);
       return Grid;
    }
};