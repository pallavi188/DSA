class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>ans;
        unordered_set<int>st;
        st.insert(nums.begin(),nums.end());
        int j =1;
        while(j<=nums.size()){
            if(st.find(j) == st.end()){
                ans.push_back(j);
            }
            j++;
        }
        return ans;
    }
};