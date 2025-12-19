class Solution {
public:
    int divisorSubstrings(int num, int k) {
        
        string s = to_string(num);
        int cnt=0,l=s.length();
        for(int i=0;i<l-k+1;i++){
            string str = s.substr(i,k);
            int n = stoi(str);
            if(n==0)continue;
            if(!(num%n)) cnt++;
        }
        return cnt;
    }
};