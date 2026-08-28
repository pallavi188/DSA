class Solution {
public:

    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(),pairs.end(),[](auto &a,auto &b){
            return a[1] < b[1];
        });
        int cntChain =0;
        int lastChainLen = INT_MIN;
        for(auto &it : pairs){
            if(it[0] >lastChainLen){
                cntChain++;
                lastChainLen = it[1];
            }
        }
        return cntChain;
    }
};