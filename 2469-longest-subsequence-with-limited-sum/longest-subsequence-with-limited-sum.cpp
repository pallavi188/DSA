class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size(),m = queries.size();
        sort(nums.begin(),nums.end());
        for(int i=1;i<n;i++){
            nums[i] += nums[i-1];
        }
        vector<int>ans(m);
        for(int i=0;i<m;i++){
            int length = 0;
            int lo =0,hi=n-1;
            while(lo<=hi){
                int mid = lo+(hi-lo)/2;
                if(nums[mid]<=queries[i]){
                    length = mid+1;
                    lo = mid+1;
                }else hi = mid-1;
            }
            ans[i] = length;
        }
        return ans;
    }
};