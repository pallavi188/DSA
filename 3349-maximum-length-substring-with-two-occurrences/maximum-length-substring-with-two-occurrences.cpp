class Solution {
public:
    int maximumLengthSubstring(string s) {
        int l = s.length();
         int len = 0;
        for(int i=0;i<l;i++){
           unordered_map<char,int>mp;
            for(int j=i;j<l;j++){
                mp[s[j]]++;
                if(mp[s[j]]>2) break;
                len = max(len,j-i+1);
            }
        }
        return len;
    }
};