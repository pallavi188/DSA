class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int n = s.length();
        int l = 0,r = n-1;
        while(r>l){
           if(s[l]!=s[r]){
               char smaller = min(s[l],s[r]);
               s[l]=smaller;
               s[r]=smaller;
           }
           l++;
           r--;
        }
       return s;
    }
};