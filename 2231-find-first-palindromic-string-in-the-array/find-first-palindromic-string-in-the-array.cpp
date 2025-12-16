class Solution {
public:
    bool ispali(string s){
        int l =0,r=s.length()-1;
        bool ans = true;
        while(l<r){
            if(s[l]!=s[r]) ans =false;
            else
            l++;
            r--;
        }
        return ans;
    }
    string firstPalindrome(vector<string>& words) {
        string ans = "";
        for(int i=0;i<words.size();i++){
            if(ispali(words[i])){
                ans += words[i];
                break;
            }
        }
        return ans;
    }
};