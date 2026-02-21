class Solution {
public:
    bool isPrime(int x){
        
        if(x<=1) return false;
        for(int i=2;i*i<=x;i++){
            if(x%i==0) return false;
        }
        return true;
    }
    int countPrimeSetBits(int left, int right) {
        int ans=0;
        for(int i=left;i<=right;i++){
            int cnt=0;
            bitset<32>b(i);
            string s = b.to_string();
            for(int j =0;j<s.length();j++){
                if(s[j]=='1')cnt++;
            }
            if(isPrime(cnt)) ans++;
        }
        return ans;
    }
};