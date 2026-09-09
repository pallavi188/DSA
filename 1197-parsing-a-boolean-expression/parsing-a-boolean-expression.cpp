class Solution {
public:
    char solveOp(vector<char>&val , char op,string s){
        if(op == '!'){
            return val[0] == 't' ? 'f' : 't';
        }
        if(op == '&'){
            for(char &ch : val){
                if(ch == 'f')return 'f';
            }
            return 't';
        }
        if(op == '|'){
            return any_of(begin(val),end(val),[](char ch) {return ch == 't';}) ? 't' : 'f';
        }
        return 't';
    }
    bool parseBoolExpr(string s) {
        int n = s.length();
        stack<char>st;
        for(int i=0;i<n;i++){
            if(s[i]==',')continue;
            if(s[i]==')'){
                vector<char>val;
                while(st.top() != '('){
                    val.push_back(st.top());
                    st.pop();
                }
                st.pop();
                char op = st.top();
                st.pop();
                st.push(solveOp(val,op,s));
            }else{
                st.push(s[i]);
            }
        }
        return st.top()=='t' ? true : false;
    }
};