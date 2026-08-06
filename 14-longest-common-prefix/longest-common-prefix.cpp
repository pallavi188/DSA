class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
     string s = "";
     int n = strs.size();
     sort(strs.begin(),strs.end());
     string word1 = strs[0];
     string word2 = strs[n-1];
     int i=0,j=0;
     while(i < word1.length() && j < word2.length()){
        if(word1[i] == word2[j]){
            s += word1[i];
            i++;
            j++;
        }
        else{
            return s;
        }
     }
     return s;
    }
};