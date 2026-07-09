class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
       //1. reverse the whole string
       reverse(s.begin(),s.end());
       int i =0,r=0,l=0;
       while(i<n){
        while(i<n && s[i] != ' '){
            s[r++] = s[i++];
        }
        if(l<r){
            reverse(s.begin()+l,s.begin()+r);
            s[r] = ' ';
            r++;
            l = r;
        }
        i++;
       }
       s = s.substr(0,r-1);
       return s;
    }
};