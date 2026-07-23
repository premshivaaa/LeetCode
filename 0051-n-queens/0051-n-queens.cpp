class Solution {
private:
    void placeQueens(int col, int n, vector<string>& board, vector<vector<string>>& result, vector<int>& sameRow, vector<int>& leftUD, vector<int>& leftLD){
        if(col == n){
            result.push_back(board);
            return;
        }

        for(int row=0; row<n; row++){
            if(!sameRow[row] && !leftUD[(n-1)+(col-row)] && !leftLD[row+col]){

                sameRow[row] = 1, leftUD[(n-1)+(col-row)] = 1, leftLD[row+col] = 1;

                board[row][col] = 'Q';
                placeQueens(col+1, n, board, result, sameRow, leftUD, leftLD);

                board[row][col] = '.';
                sameRow[row] = 0, leftUD[(n-1)+(col-row)] = 0, leftLD[row+col] = 0;
                //placeQueens(col, n, board, result, sameRow, leftUD, leftLD);
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board;
        string s(n, '.');
        for(int i=0; i<n; i++){
            board.push_back(s);
        }

        vector<int> sameRow(n, 0);
        vector<int> leftUD(2*n-1, 0);
        vector<int> leftLD(2*n-1, 0);

        placeQueens(0, n, board, result, sameRow, leftUD, leftLD);

        return result;
    }
};