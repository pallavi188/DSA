class Solution {
public:
     bool f(int i,int j,string &s){
        if(i>=j) return true;
        if(s[i] == s[j]) return f(i+1,j-1,s);
        
        return false;
     }
     string longestPalindrome(string s){
        int n = s.length();
        int maxLen =0;
        int startPoint =0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(f(i,j,s) == true){
                    if(j-i+1 > maxLen){
                        maxLen = j-i+1;
                        startPoint = i;
                    }
                }
            }
        }
        return s.substr(startPoint,maxLen);
     }
};