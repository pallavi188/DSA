class Solution {
public:
    bool bfs(int node,int n,vector<vector<int>>&graph,vector<int>&color){
        queue<int>q;
        q.push(node);
        color[node] = 0;
        while(!q.empty()){
            int currNode = q.front();
            q.pop();
            //travel its adjacent node
            for(auto it : graph[currNode]){
                if(color[it] == -1) {
                    color[it] = !color[currNode];
                    q.push(it);
                }else if(color[it] == color[currNode])return false;
            }
        }
        return true;
    } 
    bool isBipartite(vector<vector<int>>& graph) {
       int n = graph.size();
       vector<int>color(n,-1);
       for(int i=0;i<n;i++){
           if(color[i] == -1)
           if(!bfs(i,n,graph,color))return false;
       }
       return true;
    }
};