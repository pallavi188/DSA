class Solution {
public: 
    static  bool comp( const vector<int>&val1, const vector<int>&val2){
        return val1[1]<val2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n == 0)return 0;
        sort(intervals.begin(),intervals.end(),comp);
        int removeCnt = 0;
        int lastEndTime = intervals[0][1];
        for(int i=1;i<n;i++){
            //overlapping condition
            if(intervals[i][0] < lastEndTime){
                removeCnt++;
            }else{
                lastEndTime = intervals[i][1];
            }
        }
        return removeCnt;
    }
};