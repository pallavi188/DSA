class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()||matrix[0].empty()) return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        //convert char to int
        vector<vector<int>>mat(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mat[i][j] = matrix[i][j]-'0';
            }
        } 
        //row-wise prefix width
        for(int i=0;i<m;i++){
            for(int j =1;j<n;j++){
                if(mat[i][j]==1){
                    mat[i][j] += mat[i][j-1];
                }
            }
        }
        int ans = 0;
        //fix each column
        for(int j =0;j<n;j++){
            for(int i=0;i<m;i++){
                int width = mat[i][j];
                if(width == 0)continue;
                //downward expand
                int currWidth = width;
                for(int k=i;k<m && mat[k][j]>0;k++){
                    currWidth = min(currWidth , mat[k][j]);
                    int height = k-i+1;
                    ans = max(ans,currWidth * height);
                }
            }
        }
        return ans;
    }
};