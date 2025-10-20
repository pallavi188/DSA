class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<pair<int, int>> mp;
        int n = arr.size();
        if(n==0) return {};
        for (int i = 0; i < n; i++) {
            mp.push_back({arr[i], i});
        }
   
        sort(mp.begin(), mp.end());
        vector<int> rank(n);
        int r = 1;
        rank[mp[0].second] = r;

        for (int i = 1; i < n; i++) {
            if (mp[i].first != mp[i - 1].first) {
                r++;
            }
            rank[mp[i].second] = r;
        }

        return rank;
    }
};