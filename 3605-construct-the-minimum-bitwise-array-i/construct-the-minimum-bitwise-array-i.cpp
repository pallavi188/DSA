class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int>res;
        for(auto& n : nums){
            if(n & 1){
                auto x = ((n+1) &  ~n) >>1;
                res.push_back(n & ~x);
            }else 
            res.push_back(-1);
        }
        return res;
    }
};