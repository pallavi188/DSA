class Solution {
public:
    bool isPalin(string s){
        int i =0;
        int j = s.length()-1;
        while(i<=j){
            if(s[i] != s[j])return false;
            else{
                i++;
                j--;
            }
        }
        return true;
    }
    void getAllParts(string s,vector<string>&part,vector<vector<string>>&ans){
        if(s.length() == 0){
            ans.push_back(part);
            return;
        }
        for(int i=0;i<s.length();i++){
            string str = s.substr(0,i+1);
            if(isPalin(str)){
                part.push_back(str);
                getAllParts(s.substr(i+1),part,ans);
                 part.pop_back();
            }
           
        }
    }
    vector<vector<string>> partition(string s) {
       vector<vector<string>>ans;
       vector<string>part;
       getAllParts(s,part,ans);
       return ans;
    }
};