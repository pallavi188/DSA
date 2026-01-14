class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int l=0,r=0,d=0;
        int ans =0;
        for(int i=0;i<moves.length();i++){
            if(moves[i]=='L') l++;
            else if(moves[i]=='R')r++;
            else d++;
        }
        if(l>r){
            int s = l+d;
            ans = s-r;
        }
        else {
            int f = r+d;
            ans = f-l;
        }
        return ans;
    }
};