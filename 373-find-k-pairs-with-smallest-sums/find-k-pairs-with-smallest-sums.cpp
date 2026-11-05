class Solution {
public:
    typedef pair<int,pair<int,int>>p;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        priority_queue<p,vector<p>,greater<p>>pq;
        set<pair<int,int>>vis;
        if(nums1.empty() || nums2.empty() || k == 0)return {};
        int sum = nums1[0] + nums2[0];
        pq.push({sum , {0,0}});
        vis.insert({0,0});
        vector<vector<int>>res;
        while(k-- && !pq.empty()){
            auto temp = pq.top();
            pq.pop();
            int i = temp.second.first;
            int j = temp.second.second;
            res.push_back({nums1[i],nums2[j]});

            //check for next elements 
            if(j+1 < m && vis.find({i,j+1}) == vis.end()){
                pq.push({{nums1[i]+nums2[j+1]},{i,j+1}});
                vis.insert({i,j+1});
            }
            //check for i+1,j
            if(i+1 < n && vis.find({i+1,j}) == vis.end()){
                pq.push({{nums1[i+1] + nums2[j]},{i+1,j}});
                vis.insert({i+1,j});
            }
        }
        return res;
    }
};