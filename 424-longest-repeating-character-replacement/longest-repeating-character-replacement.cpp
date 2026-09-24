class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.length();
        int l=0,r=0,maxLen = 0,maxFreq = 0;
        vector<int>hash(26,0);
        while(r<n){
            hash[s[r]-'A']++;
            maxFreq = max(maxFreq,hash[s[r]-'A']);
            //trim from left side if it exceed k
            if((r-l+1)-maxFreq > k){
                hash[s[l]-'A']--;
                maxFreq =0;
                //find new MAX freq character
                
                l++;
            }
            if((r-l+1) - maxFreq <= k)
               maxLen = max(maxLen,r-l+1);
               r++;
        }
        return maxLen;
    }
};
