class Solution {
    int m,n;
    int delrow[4] = {0, 1, 0, -1};
    int delcol[4] = {-1, 0, 1, 0};
private:
    void dfs(int row, int col, vector<vector<char>>& grid, vector<vector<int>>& vis){
        vis[row][col] = 1;

        for(int i=0; i<4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol] == '1'){
                dfs(nrow, ncol, grid, vis);
            }
        }
        return;      
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int count = 0;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    dfs(i, j, grid, vis);
                    count++;
                }
            }
        }

        return count;
    }
};