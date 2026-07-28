class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                mp[grid[i][j]]++;
            }
        }
        for(auto &it : mp){
            if(it.second == 2)ans.push_back(it.first);
        }
        for(int i=1;i<=n*n;i++){
            if(mp.find(i)==mp.end())ans.push_back(i);
        }
        return ans;
    }
};