class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
       
        int n= nums.size();
        vector<int>even;
        vector<int>odd;
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(nums[i]%2 == 0){
                even.push_back(nums[i]);
            }else{
                odd.push_back(nums[i]);
            }
        }
        ans.insert(ans.end(),even.begin(),even.end());
        ans.insert(ans.end(),odd.begin(),odd.end());
        return ans;
        
    }
};