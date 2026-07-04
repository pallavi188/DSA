class Solution {
public:
    int m,n;
    vector<vector<int>>directions{{1,0},{-1,0},{0,1},{0,-1}};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
            m = maze.size();
            n = maze[0].size();
            queue<pair<pair<int,int>,int>>q;
            vector<vector<char>>vis(m,vector<char>(n,'.'));
            for(int i=0;i<m;i++){
                for(int j=0;j<n;j++){
                    if(maze[i][j] == '+') vis[i][j] = '+';
                }
            }
            int step = 0;
        q.push({{entrance[0],entrance[1]},step});
        vis[entrance[0]][entrance[1]] = '+';
         while(!q.empty()){
            auto it =  q.front();
            q.pop();
            int i = it.first.first;
            int j = it.first.second;
            int step = it.second;
            if((i != entrance[0] || j != entrance[1]) && (i==0||i==m-1||j==0||j==n-1)){
                return step;
            }
            //explore the neighbour
            for(vector<int> &dir : directions){
                int new_r = i + dir[0];
                int new_c = j + dir[1];
                
                if(new_r>=0 && new_r<m && new_c>=0 && new_c<n && maze[new_r][new_c] != '+' && vis[new_r][new_c] != '+'){
                    q.push({{new_r,new_c},step+1});
                    vis[new_r][new_c] = '+';
                }
            }
         }
         return -1;
    } 
};