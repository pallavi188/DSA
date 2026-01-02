class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        int ans =0;
        unordered_map<int,int>freq;
        for(int x : nums){
            freq[x]++;
        }
        for(auto y : freq){
            if(y.second==n/2){
                ans = y.first;
            }
        }
        return ans;
    }
};