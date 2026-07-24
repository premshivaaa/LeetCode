class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<unordered_set<int>> row(9);
        vector<unordered_set<int>> col(9);
        vector<unordered_set<int>> box(9);

        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j] == '.') continue;

                int num = board[i][j] - '1';
                int k = (i/3) * 3 + (j/3);

                if(row[i].count(num) || col[j].count(num) || box[k].count(num)) return false;

                row[i].insert(num);
                col[j].insert(num);
                box[k].insert(num);
            }
        }

        return true;
    }
};