class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>&ans,
    vector<vector<int>>&image,int newColor ,int delRow[],int delCol[],int initialColor){
        ans[row][col]=newColor;
        int n = image.size();
        int m = image[0].size();
        for(int i=0;i<4;i++){
            int nRow = row + delRow[i];
            int nCol = col + delCol[i];
            if(nRow>=0 && nRow<n && nCol <m && nCol>=0 &&image[nRow][nCol]==initialColor
            && ans[nRow][nCol] != newColor){
                dfs(nRow,nCol,ans,image,newColor,delRow,delCol,initialColor);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int initialcolor = image[sr][sc];
        vector<vector<int>>ans = image;
        int delRow[]={-1,0,1,0};
        int delCol[] = {0,1,0,-1};
        dfs(sr,sc,ans,image,color,delRow,delCol,initialcolor);
        return ans;
    }
};