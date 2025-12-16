class Solution {
public:
    vector<int> diStringMatch(string s) {
        int l =0,r = s.length();
        vector<int>ans;
        for(int j=0;j<s.length();j++){
            if(s[j]=='I'){
                ans.push_back(l);
                l++;
            }else{
                ans.push_back(r);
                r--;
            }
        }
        ans.push_back(l);
        return ans;
    }
};