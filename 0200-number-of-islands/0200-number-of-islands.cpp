class Solution {

private:
    void traverse(int row, int col, vector<vector<char>>& grid, int m, int n){
        grid[row][col] = '0';
        queue<pair<int,int>> q;
        q.push({row,col});

        int delrow[] = {-1, 0, 1, 0};
        int delcol[] = {0, 1, 0, -1};


        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++){
                int nrow = delrow[i] + row;
                int ncol = delcol[i] + col;

                if(nrow < m && nrow >= 0 && ncol < n && ncol >= 0 && grid[nrow][ncol] == '1'){
                    grid[nrow][ncol] = '0';
                    q.push({nrow, ncol});
                } 
            }
        }
  
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // vector<vector<int>> vis(m , vector<int>(n, 0));
        int count = 0;

        for(int row = 0; row < m; row++){
            for(int col = 0; col < n; col++){
                if(grid[row][col] == '1'){
                    traverse(row, col, grid, m, n);
                    count++;
                }
            }
        }

        return count;
    }
};