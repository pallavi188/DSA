class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int startIdx = 0;
        int currGas = 0;
        int totalGas = 0;
        int totalCost = 0;
        
        for(int val : gas){
            totalGas += val;
        }
        for(int val : cost){
            totalCost += val;
        }
        if(totalGas < totalCost) return -1;

        int n = gas.size();
        for(int i=0;i<n;i++){
            currGas += (gas[i] - cost[i]);
            if(currGas < 0){
                startIdx = i+1;
                currGas = 0;
            }
        }
        return startIdx;
    }
};