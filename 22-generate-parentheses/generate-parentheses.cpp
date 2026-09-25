class Solution {
public:
    void f(int n,int open,int close,string &currStr,vector<string>&ans){
        if(open == n && close == n){
            ans.push_back(currStr);
            return;
        }
        //ith char can be open bracket if no. of open bracket so far is less than n
        if(open < n){
            currStr.push_back('(');
            f(n,open+1,close,currStr,ans);
            currStr.pop_back();
        }
        //ith char can be close bracket if no. of close bracket is less than the number of open bracket
        if(close < open){
            currStr.push_back(')');
            f(n,open,close+1,currStr,ans);
            currStr.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
       vector<string>ans;
       string currStr;
       f(n,0,0,currStr,ans);
       return ans;
    }
};