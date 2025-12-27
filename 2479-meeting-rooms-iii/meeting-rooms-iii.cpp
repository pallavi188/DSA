class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(),meetings.end());
        vector<int>count(n);
        vector<long long>timer(n);
        int iterator =0;
        while(iterator < meetings.size()){
            int start = meetings[iterator][0];
            int end = meetings[iterator][1];
            long long duration = end - start;
            int room = -1;
            long long earliest = LLONG_MAX;
            int earliestRoom = -1;

            for(int i=0;i<n;i++){
                if(timer[i]<earliest){
                    earliest = timer[i];
                    earliestRoom = i;

                }
                if(timer[i]<=start){
                    room = i;
                    break;
                }
            }
            if(room != -1){
                timer[room] = end;
                count[room]++;
            }else{
                timer[earliestRoom] += duration;
                count[earliestRoom]++;
            }
            iterator++;
        }
        int maxi =0,idx =0;
        for(int i=0;i<n;i++){
            if(count[i]>maxi){
                maxi = count[i];
                idx= i;
            }
        }
        return idx;
    }
};