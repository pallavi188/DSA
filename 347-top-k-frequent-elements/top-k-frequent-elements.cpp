class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        unordered_map<int,int>freq;
        int n = nums.size();
        for(int i=0;i<n;i++){
            freq[nums[i]]++;
        }
        vector<pair<int,int>>v;
        for(auto &it:freq){
          v.push_back({it.second,it.first});
        }
        sort(v.rbegin(),v.rend());
        for(int i=0;i<k;i++){
            ans.push_back(v[i].second);
        }
        return ans;
    }
};