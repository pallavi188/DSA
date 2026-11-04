class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>>vec;
        
        int n = nums1.size();
        for(int i=0;i<n;i++){
          vec.push_back({nums1[i],nums2[i]});
        }
        //comparator for sorting
        auto lambda = [&](auto &p1,auto &p2){
            return p1.second > p2.second;
        };
        sort(begin(vec),end(vec),lambda);
        priority_queue<int,vector<int>,greater<int>>pq;
        long long kSum = 0;
        for(int i=0;i<=k-1;i++){
            kSum += vec[i].first;
            pq.push(vec[i].first);
        }
        long long res = kSum * vec[k-1].second;
        for(int i=k;i<n;i++){
            //try all remaining elements as minimum
            kSum += vec[i].first - pq.top();
            pq.pop();
            pq.push(vec[i].first);
            res = max(res , kSum*vec[i].second);
        }
        return res;
    }
};