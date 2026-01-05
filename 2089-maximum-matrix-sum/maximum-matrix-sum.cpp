class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long totalSum = 0;
        int neg = 0;
        int minAbs = INT_MAX;
        for(auto& row : matrix){
            for(int v : row){
                if(v < 0)neg++;
                int avg= abs(v);
                totalSum += avg;
                minAbs = min(minAbs,avg);
            }
        }
        return (neg %2 == 0) ? totalSum : totalSum - 2LL*minAbs;
    }
};