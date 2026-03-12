class Solution {
    int delrow[4] = {-1, 0, 1, 0};
    int delcol[4] = {0, -1, 0, 1};
    //int m, n;

private:
    void dfs(int row, int col, vector<vector<int>>& vis, vector<vector<int>>& grid, int m , int n){
        vis[row][col] = 1;

        for(int i=0; i<4; i++){
            int nrow = delrow[i] + row;
            int ncol = delcol[i] + col;

            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                dfs(nrow, ncol, vis, grid, m, n);
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));

        for(int j=0; j<n; j++){
            if(!vis[0][j] && grid[0][j]) dfs(0, j, vis, grid, m, n);
                
            if(!vis[m-1][j] && grid[m-1][j]) dfs(m-1, j, vis, grid, m, n);
                
        }
        for(int i=0; i<m; i++){
            if(!vis[i][0] && grid[i][0]) dfs(i, 0, vis, grid, m, n);
                
            if(!vis[i][n-1] && grid[i][n-1]) dfs(i, n-1, vis, grid, m, n);
                
        }

        int lands = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    lands++;
                }
            }
        }

        return lands;
    }
};