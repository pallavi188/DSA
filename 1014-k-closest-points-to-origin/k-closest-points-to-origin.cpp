class Solution {
public:
    int squaredDist(vector<int>v){
        return v[0]*v[0]+v[1]*v[1];
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>>maxHeap;
        for(auto p : points){
            int dist = squaredDist(p);
            if(maxHeap.size()<k) maxHeap.push({dist,p});
            else if(dist < maxHeap.top().first){
                maxHeap.pop();
                maxHeap.push({dist,p});
            }
        }
        points.clear();
        while(!maxHeap.empty()){
            points.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        return points;
    }
};