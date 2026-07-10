class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        if(n != m) return false;
        vector<int>freq1(26);
        vector<int>freq2(26);
        for(int i=0;i<n;i++){
           freq1[word1[i]-'a']++;
           freq2[word2[i]-'a']++;
        }
        for(int i=0;i<26;i++){
            if(freq1[i]!=0 && freq2[i]!=0) continue;
            if(freq1[i]==0 && freq2[i]==0)continue;
            return false;
        }
        sort(begin(freq1),end(freq1));
        sort(begin(freq2),end(freq2));
        return freq1==freq2;
    }
};