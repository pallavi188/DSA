class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));

        for (auto& g : guards) {
            grid[g[0]][g[1]] = 1;
        }
        for (auto& w : walls) {
            grid[w[0]][w[1]] = 2;
        }
        vector<vector<bool>> guarded(m, vector<bool>(n, false));
        vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

        for (auto& g : guards) {
            int x = g[0], y = g[1];
            for (auto& d : dir) {
                int nx = x + d.first, ny = y + d.second;
                while (nx >= 0 && nx < m && ny >= 0 && ny < n &&
                       grid[nx][ny] != 1 && grid[nx][ny] != 2) {
                    guarded[nx][ny] = true;
                    nx += d.first;
                    ny += d.second;
                }
            }
        }

        int count = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // cell should be empty and not guarded
                if (grid[i][j] == 0 && !guarded[i][j])
                    count++;
            }
        }

        return count;
    }
};