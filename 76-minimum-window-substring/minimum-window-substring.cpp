class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length();
        if(t.length()>n)return "";
        unordered_map<char,int>mp;
        for(char ch : t)mp[ch]++;
        int reqCnt = t.length();
        int i=0,j=0;
        int minWindowSize = 1e9;
        int st_i = 0;
        while(j<n){
            char ch = s[j];
            if(mp[ch] > 0) reqCnt--;
            mp[ch]--;
            while(reqCnt == 0){
                int currWindowSize = j-i+1;
                if(minWindowSize > currWindowSize){
                    minWindowSize = currWindowSize;
                    st_i = i;
                }
                mp[s[i]]++;
                if(mp[s[i]] > 0) reqCnt++;
                i++;
            }
            j++;
        }
        return minWindowSize == 1e9 ? "": s.substr(st_i,minWindowSize);
    }
};