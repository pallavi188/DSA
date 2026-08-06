class Solution {
public:
    bool isFreqSame(int freq[26],int windowFreq[26]){
        for(int i=0;i<26;i++){
            if(freq[i] != windowFreq[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        int freq[26] = {0};
        for(int i=0;i<s1.length();i++){
            freq[s1[i]-'a']++;
        }
        int windowSize = s1.length();
        for(int i=0;i<s2.length();i++){
            int windowFreq[26] = {0};
            int windowIdx = 0;
            int idx = i;
            while(windowIdx < windowSize && idx < s2.length()){
                windowFreq[s2[idx]-'a']++;
                windowIdx++;
                idx++;
            }
            if(isFreqSame(freq,windowFreq)) return true;
        }
        return false;
    }
};