class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int minFinish = INT_MAX;
        int n = landStartTime.size();
        int m = waterStartTime.size();

        for(int i=0;i<n;++i){
            int landStart= landStartTime[i];
            int landDur = landDuration[i];

            for(int j=0;j<m;++j){
                int waterStart = waterStartTime[j];
                int waterDur = waterDuration[j];
                
                int landEnd = max(landStart,0)+landDur ; 
                int waterAfterLand = max(waterStart , landEnd);
                int finish1 = waterAfterLand + waterDur ;

                int waterEnd = max(waterStart,0)+waterDur;
                int landAfterWater = max(landStart,waterEnd);
                int finish2 = landAfterWater +landDur ;
                
                 minFinish = min({minFinish,finish1,finish2});
            }
        }
        return minFinish;
    }
};