class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int totalTime=0;
        int prev = 0;

        for(int i=1;i<colors.length();i++){
            if(colors[i]==colors[prev]){
                if(neededTime[i]<neededTime[prev]){
                    totalTime += neededTime[i];
                }else{
                    totalTime += neededTime[prev];
                    prev = i;
                }
            }else{
                prev = i;
            }
        }
        return totalTime;
    }
};