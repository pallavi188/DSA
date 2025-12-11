class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlen =0;
        
        for(int i=0;i<s.length();i++){
            string t = "";
            for(int j=i;j<s.length();j++){
                if(t.find(s[j])==string::npos){
                   t +=s[j];
                   maxlen = max(maxlen,(int)t.length());
                } else
                break;
                
            }
        }
        return maxlen;
    }
};