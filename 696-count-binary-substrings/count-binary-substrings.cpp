class Solution {
public:
    int countBinarySubstrings(string s) {
        int cnt =1;
        int idx = 0;
        vector<int>ans(s.size());
        for(int i =1;i<s.size();i++){
            if(s[i]==s[i-1]){
                cnt++;
            }else{
                ans[idx++] = cnt;
                cnt=1;
            }
        }
        ans[idx++] = cnt;
        int sum = 0;
        for(int i=0;i<idx-1;i++){
            sum += min(ans[i],ans[i+1]);
        }
        return sum;
    }
};