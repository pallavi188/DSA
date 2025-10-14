class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());

        vector<int>result;

        unordered_map<int,int>freq1;
        for(int i=0;i<nums1.size();i++){
            freq1[nums1[i]]++;
        }
      for(int j=0;j<nums2.size();j++){
        if(freq1[nums2[j]]>0){
             result.push_back(nums2[j]);
             freq1[nums2[j]]--;
        }
      }
      return result;
    }
};