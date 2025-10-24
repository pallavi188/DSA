class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end(),greater<>());
        int total = accumulate(nums.begin(),nums.end(),0);
        vector<int>ans;
        int sum =0;
        for(int num : nums){
            sum += num;
            ans.push_back(num);
            if(sum>total-sum) break;
        }
      return ans;
    }
};