class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();
        vector<bool>resolve(n-1,false);
        int unresolve = n-1;
        int del = 0;
        for(int c=0;c<m && unresolve>0;c++){
            bool bad = false;
            for(int i=0;i<n-1;i++){
                if(!resolve[i] && strs[i][c]>strs[i+1][c]){
                    bad = true;
                    break;
                }
            }
            if(bad){
                del++;
                continue;
            }
            for(int i=0;i<n-1;i++){
                if(!resolve[i] && strs[i][c]<strs[i+1][c]){
                    resolve[i] = true;
                    unresolve--;
                }
            }
        }
        return del;
    }
};