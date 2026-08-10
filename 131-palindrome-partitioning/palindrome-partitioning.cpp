class Solution {
public:
    bool isPalin(string s){
        int n = s.length();
        int i=0,j=n-1;
        while(i<=j){
            if(s[i] != s[j])return false;
            else{
                i++;
                j--;
            }
        }
        return true;
    }
    void getAllParts(string s,vector<string>&partition,vector<vector<string>>&ans){
        if(s.length() == 0){
            ans.push_back(partition);
            return;
        }
        for(int i=0;i<s.length();i++){
            string part = s.substr(0,i+1);
            if(isPalin(part)){
                partition.push_back(part);
                getAllParts(s.substr(i+1),partition,ans);
                partition.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>partition;
        getAllParts(s,partition,ans);
        return ans;
    }
};