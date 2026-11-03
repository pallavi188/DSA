class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      int n = nums.size();
      unordered_map<int,int>freq;
      for(int i=0;i<n;i++){
        freq[nums[i]]++;
      }
      vector<pair<int,int>>vec;
      for(auto &it : freq){
        vec.push_back({it.first,it.second});
      }
      //sort the vector on the basis of freq
      sort(vec.begin(), vec.end(), [](pair<int,int>&a, pair<int,int>&b) {
            return a.second > b.second;
        });

      vector<int>ans;
      for(int i=0;i<k;i++){
        ans.push_back(vec[i].first);
      }
      return ans;
    }
};