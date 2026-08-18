class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& preR) {
        int v = numCourses;
       //form the graph
       vector<int>adj[v];
       for(auto it:preR){
        adj[it[1]].push_back(it[0]);
       }
      //1.indegree calculation for each node
      vector<int>indegree(v,0);
      for(int i=0;i<v;i++){
        for(auto it : adj[i]){
            indegree[it]++;
        }
      }
      //2.queue formation
      queue<int>q;
      for(int i=0;i<v;i++){
        if(indegree[i]==0){
            q.push(i);
        }
      }
      vector<int>topoOrder;
      while(!q.empty()){
        int node = q.front();
        q.pop();
        topoOrder.push_back(node);
        for(auto it : adj[node]){
            indegree[it]--;
            if(indegree[it]==0)q.push(it);
        }
      }
      if(topoOrder.size() == v)return topoOrder;
      else
      return {};
    }
};