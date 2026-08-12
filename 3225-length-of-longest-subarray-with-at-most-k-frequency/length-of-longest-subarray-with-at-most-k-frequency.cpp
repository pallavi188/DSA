class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>freq;
        int start = 0;
        int charFreq = 0;
        for(int end=0;end<n;end++){
            freq[nums[end]]++;
            if(freq[nums[end]] == k+1){
                charFreq++;
            }
            if(charFreq > 0){
                freq[nums[start]]--;
                if(freq[nums[start]] == k){
                    charFreq--;
                }
                start++;
            }
        }
        return n - start;
    }
};