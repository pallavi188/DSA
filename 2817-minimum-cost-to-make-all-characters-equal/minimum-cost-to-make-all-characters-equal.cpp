class Solution {
public:
    long long minimumCost(string s) {
        int n = s.length();
        long long cost=0;
        for(int i=1;i<=n/2;i++){
            if(s[i-1] != s[i]) cost += i;
        }
        for(int i = n/2+1;i<n;i++){
            if(s[i-1] != s[i]) cost += n-i;
        }
        return cost;
    }
};