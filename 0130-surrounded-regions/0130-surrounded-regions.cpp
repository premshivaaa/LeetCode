class Solution {
    int delrow[4] = {-1, 0, 1, 0};
    int delcol[4] = {0, -1, 0, 1};

private:
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& vis, int m, int n){
        vis[row][col] = 1;

        for(int i=0; i<4; i++){
            int nrow = delrow[i] + row;
            int ncol = delcol[i] + col;

            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && board[nrow][ncol] == 'O' && !vis[nrow][ncol]){
                dfs(nrow, ncol, board, vis, m, n);
            }
        }
    }

public:    
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));

        // rows
        for(int j=0; j<n; j++){
            if(!vis[0][j] && board[0][j] == 'O'){
                dfs(0, j, board, vis, m, n);
            }
            if(!vis[m-1][j] && board[m-1][j] == 'O'){
                dfs(m-1, j, board, vis, m, n);
            }
        }
        // cols
        for(int i=0; i<m; i++){
            if(!vis[i][0] && board[i][0] == 'O'){
                dfs(i, 0, board, vis, m, n);
            }
            if(!vis[i][n-1] && board[i][n-1] == 'O'){
                dfs(i, n-1, board, vis, m, n);
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!vis[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }

    }
};