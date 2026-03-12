class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        
        string s = bitset<32>(n).to_string();
        s=s.substr(s.find('1'));
        for(int i=0;i<s.length();i++){
            if(s[i]=='0') s[i]='1';
            else
            s[i]='0';
        }
        int num = bitset<32>(s).to_ulong();
        return num;
    }
};