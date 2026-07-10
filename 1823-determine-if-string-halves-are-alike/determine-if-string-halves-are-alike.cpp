class Solution {
public:
    bool halvesAreAlike(string s) {
        int n = s.length();
        int vowelA=0,vowelB=0;
        for(int i=0;i<n/2;i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||
           s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')vowelA++;
        }
        for(int i=n/2;i<n;i++){
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||
           s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U')vowelB++;
        }
        if(vowelA == vowelB)return true;
        else
        return false;
    }
};