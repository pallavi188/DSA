class Solution {
public:
    int minimumLength(string s) {
        int  n = s.length();
        int st = 0;
        int end = n-1;
        while(st < end && s[st]==s[end]){
            char ch = s[st];
            while(st < end && s[st]==ch)st++;
            while(end>=st && s[end]==ch)end--;
        }
        return end-st+1;
    }
};