class Solution {
public:
    int n;
    unordered_set<string>st;
    int maxLen; 
    void solve(int i,string &curr,string &s,int cnt){
          if(cnt < 0)return;
          if(i == n){
            if(cnt == 0){
                if(curr.length() > maxLen){
                    maxLen = curr.length();
                    st.clear();
                }
                if(curr.length() == maxLen)st.insert(curr);
            }
            return;
          }
          if(s[i] != '(' && s[i] != ')'){
            curr.push_back(s[i]);
            solve(i+1,curr,s,cnt);
            curr.pop_back();
            return;
          }
        curr.push_back(s[i]);
        solve(i+1,curr,s,cnt + (s[i]=='(' ? 1 : -1));
        curr.pop_back();
        solve(i+1,curr,s,cnt);
    }
    vector<string> removeInvalidParentheses(string s) {
        n = s.length();
        st.clear();
        maxLen = 0;
        string curr = "";
        solve(0,curr,s,0);
        return vector<string>(begin(st),end(st));
    }
};