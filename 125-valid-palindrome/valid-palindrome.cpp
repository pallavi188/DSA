class Solution {
public:
    bool isPalin(string t){
        int n = t.length();
        int i=0,j=n-1;
        while(i<=j){
            if(t[i] == t[j]){
                i++;
                j--;
            }else{
                return false;
            }
        }
        return true;
    }
    bool isPalindrome(string s) {
         int n = s.length();
         if(n == 0)return true;
         string t = "";
         for(int i=0;i<n;i++){
            
            if(!isalnum(s[i])){
                continue;
            }
            t += tolower(s[i]);
         }   
         return isPalin(t);
    }
};