class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        int size = pow(2,n);
        vector<int>num(size,0);
        for(string p : nums){
            int val = stoi(p , NULL,2);
            num[val]++;
        }
        for(int i=0;i<size;i++){
            if(num[i] == 0){
                string ans = bitset<32>(i).to_string();
                ans = ans.substr(32-n);
                return ans;
            }
        }
        return string(n,'0');
    }
};