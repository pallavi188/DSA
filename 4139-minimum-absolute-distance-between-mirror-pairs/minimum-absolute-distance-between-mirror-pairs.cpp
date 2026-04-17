class Solution {
public:
    int reverseNumber(int n) {
    int rev = 0;
    while(n > 0) {
        int digit = n % 10;
        rev = rev * 10 + digit;
        n /= 10;
    }
    return rev;
}
    int minMirrorPairDistance(vector<int>& nums) {
        int ans = INT_MAX;
        unordered_map<int,int>mp;
        int n = nums.size();
        for(int i=0;i<n;i++){
           if(mp.count(nums[i])){
            ans = min(ans,i - mp[nums[i]]);
           }
           mp[reverseNumber(nums[i])] = i;
        }
        if(ans == INT_MAX)return -1;
        return ans;
    }
};