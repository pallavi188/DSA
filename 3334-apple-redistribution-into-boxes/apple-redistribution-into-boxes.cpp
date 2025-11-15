class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.begin(),capacity.end(),greater<>());
        long long ap = 0;
        int cnt =0,sum=0;
        for(int a : apple){
            ap += a;
        }
        int i=0;
        while(sum<ap && i< capacity.size()){
            sum += capacity[i];
            cnt++;
            i++;
        }
        return cnt;
    }
};