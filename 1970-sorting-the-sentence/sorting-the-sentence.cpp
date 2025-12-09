class Solution {
public:
    string sortSentence(string s) {
          
          vector<string>temp(10);
          string word;
          for(int i=0;i<s.length();i++){
            if(isdigit(s[i])){
                temp[s[i]-'0'] = word;
                word = "";
                i++;
            }else{
                word +=s[i];
            }
          }
          string ans = "";
          for(int i=1;i<10;i++){
            if(temp[i].size()>0){
                ans += temp[i]+" ";
            }
          }
          if(!ans.empty()) ans.pop_back();
          return ans;
    }
};