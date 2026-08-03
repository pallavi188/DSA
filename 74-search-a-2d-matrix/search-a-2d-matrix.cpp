class Solution {
public:
    bool searchRow(int target,vector<vector<int>>&matrix,int row){
        int n = matrix[0].size();
        int st = 0,end = n-1;
        while(st <= end){
            int mid = st + (end-st)/2;
            if(matrix[row][mid] == target) return true;
            else if(matrix[row][mid] > target) end = mid-1;
            else
            st = mid+1;
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int r = matrix.size();
       int c = matrix[0].size();
       int stRow = 0,endRow = r-1;
       while(stRow <= endRow){
        int midRow = stRow + (endRow - stRow)/2;
        if(target >= matrix[midRow][0] && target <= matrix[midRow][c-1]){
            //call a function that will perform BS on that row
            return searchRow(target,matrix,midRow);
        }else if(target > matrix[midRow][c-1]) stRow = midRow+1;
        else
        endRow = midRow-1;
       }
       return  false;
    }
};