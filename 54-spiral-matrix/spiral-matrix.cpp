class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int>order;
        int srow =0,scol =0,erow = m-1,ecol=n-1;
        while(srow<=erow &&scol<=ecol){
            //top noundary
            for(int i=scol;i<=ecol;i++){
                order.push_back(matrix[srow][i]);
            }
            //right boundary
            for(int j=srow+1;j<=erow;j++){
                order.push_back(matrix[j][ecol]);
            }
            //bottom boundary
            for(int j=ecol-1;j>=scol;j--){
                if(srow == erow)break;
                else
                order.push_back(matrix[erow][j]);
            }
            //left boundary
            for(int i=erow-1;i>=srow+1;i--){
                if(scol == ecol)break;
                order.push_back(matrix[i][scol]);
            }
            srow++;
            erow--;
            scol++;
            ecol--;
        }
        return order;
    }
};