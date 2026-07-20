class Solution {
    int n, m;
    int delrow[4] = {0, -1, 0, 1};
    int delcol[4] = {-1, 0, 1, 0};
private:
    void dfs(int row, int col, vector<vector<char>>& board, vector<vector<int>>& vis){
        vis[row][col] = 1;
        
        for(int k=0; k<4; k++){
            int nrow = row + delrow[k];
            int ncol = col + delcol[k];
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && board[nrow][ncol] == 'O'){
                dfs(nrow, ncol, board, vis);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        
        for(int j=0; j<m; j++){
            if(!vis[0][j] && board[0][j] == 'O') dfs(0, j, board, vis);
            
            if(!vis[n-1][j] && board[n-1][j] == 'O') dfs(n-1, j, board, vis);
        }
        for(int i=0; i<n; i++){
            if(!vis[i][0] && board[i][0] == 'O') dfs(i, 0, board, vis);
            
            if(!vis[i][m-1] && board[i][m-1] == 'O') dfs(i, m-1, board, vis);
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j]) board[i][j] = 'X';
            }
        }
    }
};