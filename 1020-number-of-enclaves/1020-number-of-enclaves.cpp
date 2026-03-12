class Solution {
    int delrow[4] = {-1, 0, 1, 0};
    int delcol[4] = {0, -1, 0, 1};
    int m, n;

private:
    void dfs(int row, int col, vector<vector<int>>& grid){
        grid[row][col] = 0;

        for(int i=0; i<4; i++){
            int nrow = delrow[i] + row;
            int ncol = delcol[i] + col;

            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && grid[nrow][ncol] == 1){
                dfs(nrow, ncol, grid);
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        //vector<vector<int>> vis(m, vector<int>(n, 0));

        for(int j=0; j<n; j++){
            if(grid[0][j]) dfs(0, j, grid);
                
            if(grid[m-1][j]) dfs(m-1, j, grid);
                
        }
        for(int i=0; i<m; i++){
            if(grid[i][0]) dfs(i, 0, grid);
                
            if(grid[i][n-1]) dfs(i, n-1, grid);
                
        }

        int lands = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    lands++;
                }
            }
        }

        return lands;
    }
};