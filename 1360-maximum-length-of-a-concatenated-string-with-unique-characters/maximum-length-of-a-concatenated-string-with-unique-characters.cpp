class Solution {
public:
    bool isDuplicate(string &s1,string &s2){
        int arr[26] = {0};
        for(char &ch : s1){
            if(arr[ch - 'a']>0) return true;
            arr[ch-'a']++;
        }
        for(char &ch : s2){
            if(arr[ch-'a']>0) return true;
        }
        return false;
    }
    int f(int idx,string temp,vector<string>&arr){
        if(idx>=arr.size()) return temp.length();
        int pick =0;
        int not_pick = 0;
        if(isDuplicate(arr[idx],temp)){
            not_pick = f(idx+1,temp,arr);
        }
        else{
            not_pick = f(idx+1,temp,arr);
            pick = f(idx+1,temp+arr[idx],arr);
        }
        return max(pick,not_pick);
    }
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        string temp="";
        return f(0,temp,arr);
    }
};