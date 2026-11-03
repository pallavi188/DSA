class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        //form a new vector that store the enqueue time , duration and the index of the tasks
        vector<array<int,3>>idxArray;
        for(int i=0;i<n;i++){
            idxArray.push_back({tasks[i][0],tasks[i][1],i});
        }
        //sort it on the basis of start time
        sort(idxArray.begin(),idxArray.end());
        vector<int>result;
        long long curr_time = 0;
        int idx = 0;
        //define a min heap priority_queue to store on the basis of duration and idx 
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        while(idx < n || !pq.empty()){
            if(pq.empty() && curr_time < idxArray[idx][0]){
                curr_time =  idxArray[idx][0];
            }
            //push all those elements in the min heap that has enqueue time less than or equal to the curr time
            while(idx<n && idxArray[idx][0] <= curr_time){
                pq.push({idxArray[idx][1],idxArray[idx][2]});
                idx++;
            }
            pair<int,int>curr_task = pq.top();
            pq.pop();
            curr_time += curr_task.first;
            result.push_back(curr_task.second);
        }
        return result;
    }
};