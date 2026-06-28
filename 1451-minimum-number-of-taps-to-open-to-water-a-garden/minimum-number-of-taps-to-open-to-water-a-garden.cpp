class Solution {
public:
    map<pair<int,int>,int>mp;
    int f(int idx,int maxEnd,int n,vector<pair<int,int>>&area){
        if(idx >= area.size()){
            if(maxEnd >= n) return 0;
            else
            return 1e9;
        }
        if(maxEnd < area[idx].first) return 1e9;
        if(mp.find({idx,maxEnd}) != mp.end()) return mp[{idx,maxEnd}];

        int not_open = f(idx+1,maxEnd,n,area);
        int open = 1 + f(idx+1,max(maxEnd,area[idx].second),n,area);
        return mp[{idx,maxEnd}] = min(open,not_open);
    }
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int,int>>area;
        for(int i=0;i<ranges.size();i++){
            int st = i-ranges[i];
            int end = i+ranges[i];
            area.push_back({st,end});
        }
        
        sort(area.begin(),area.end());
        int ans = f(0,0,n,area);
        if(ans != 1e9) return ans;
        else
        return -1;
    }
};