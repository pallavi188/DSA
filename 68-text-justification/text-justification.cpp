class Solution {
public:
    string findLine(int i,int j,int eachSpace,int extraSpace,vector<string>&words,int maxWidth){
        string line = "";
        for(int k=i;k<j;k++){
            line += words[k];

            if(k == j-1){
                continue;
            }
            for(int spc = 1;spc<=eachSpace;spc++){
                line += " ";
            }
            if(extraSpace>0){
                line += " ";
                extraSpace--;
            }
        }
        while(line.length()<maxWidth){
            line += " ";
        }
        return line;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();
        vector<string>result;
        int  i =0;
        while(i<n){
            int letterCnt = words[i].length();
            int j = i+1;
            int space = 0;
            while(j<n && words[j].length()+1+space+letterCnt <= maxWidth){
                letterCnt += words[j].length();
                space += 1;
                j++;
            }
            int remainingSlot = maxWidth - letterCnt;
            int eachSpace = space == 0 ? 0 : remainingSlot / space;
            int extraSpace = space == 0 ? 0 : remainingSlot%space;
             
            //last line
            if(j==n){
                eachSpace = 1;
                extraSpace = 0;
            } 
            result.push_back(findLine(i,j,eachSpace,extraSpace,words,maxWidth));
            i=j;
        }
        return result;
    }
};