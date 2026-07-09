class Solution {
public:
    bool isVowel(char &ch){
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||
           ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')return true;
        
        return false;   
    }
    string reverseVowels(string s) {
        int n = s.length();
        int st = 0;
        int end = n-1;
        while(st<end){
            if(!isVowel(s[st])){
                st++;
            }else if(!isVowel(s[end])){
                end--;
            }else{
                swap(s[st],s[end]);
                st++;
                end--;
            }
        }
        return s;
    }
};