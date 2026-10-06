class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        //sort the intervals on the basis of its start time
        sort(begin(intervals),end(intervals));
        //min heap to store the ending point of each group
        priority_queue<int,vector<int>,greater<int>>pq;
        //step 3. process each intervals
        for(auto & interval : intervals){
            int st = interval[0];
            int end = interval[1];
            if(!pq.empty() && st > pq.top()){
                pq.pop();
            }
            pq.push(end);
        }
        return pq.size();
    }
};