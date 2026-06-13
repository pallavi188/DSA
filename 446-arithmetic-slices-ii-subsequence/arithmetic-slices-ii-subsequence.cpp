class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        unordered_map<long long,int>mp[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                long long diff = (long long)nums[i]-nums[j];
                int countJ = mp[j].count(diff) ? mp[j][diff]:0;
                mp[i][diff] += countJ +1;
                result += countJ;
            }
        }
        return result;
    }
};