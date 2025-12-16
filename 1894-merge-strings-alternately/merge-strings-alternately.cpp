class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string s = "";
        int l =0,r=0;
        while(l != word1.length() && r != word2.length()){
             s += word1[l];
             l++;
             s += word2[r];
             r++;
        }
        if(l != word1.length()){
            for(int i=l;i<word1.length();i++){
                s += word1[i];
            }
        }
        if(r != word2.length()){
            for(int i=r;i<word2.length();i++){
                s += word2[i];
            }
        }
        return s;
    }
};