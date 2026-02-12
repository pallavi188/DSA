class Solution {
public:
    int longestBalanced(string s) {
        int n = s.length();
        int maxLen = 0;
        for(int i =0;i<n;i++){
            vector<int>freq(26,0);
            for(int j =i;j<n;j++){
                freq[s[j]-'a']++;
                int count =0;
                bool balance = true;
                for(int f : freq){
                    if(f>0){
                        if(count==0) count = f;
                        else if(count != f){
                            balance = false;
                            break;
                        }
                    }
                }
                if(balance) maxLen = max(maxLen,j-i+1);
            }
        }
        return maxLen;
    }
};