class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.length();
        int min_op = INT_MAX;
        for(int i=0;i<=n-k;i++){
             int len = 0;
            for(int j = i;j<i+k;j++){
                if(blocks[j]=='W') len++;
            }
           min_op = min(min_op,len);
        }
        return min_op;
    }
};