class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>mp;
        for(int num : nums){
            mp.insert(num);
        }
        for(int i=1; ; i++){
            if(mp.find(k*i) == mp.end())return k*i;
        }
    }
};