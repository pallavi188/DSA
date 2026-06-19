class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        vector<int>ans;
        ans.push_back(0);
        int j =0;
        for(int i=0;i<gain.size();i++){
            ans.push_back(ans[j]+gain[i]);
            j++;
        }
        int maxi = ans[0];
        for(int j=1;j<ans.size();j++){
            maxi = max(maxi,ans[j]);
        }
        return maxi;
    }
};