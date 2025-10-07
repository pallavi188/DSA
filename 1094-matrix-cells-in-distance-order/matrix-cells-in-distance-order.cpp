class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>>cell;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                cell.push_back({i,j});
            }
        }
         sort(cell.begin(), cell.end(), [&](vector<int>& a, vector<int>& b) {
            int distA = abs(a[0] - rCenter) + abs(a[1] - cCenter);
            int distB = abs(b[0] - rCenter) + abs(b[1] - cCenter);
            return distA < distB;
        });
        return cell;    
    }
};