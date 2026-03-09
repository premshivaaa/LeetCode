class Solution {

private:
    void dfs(int row, int col, vector<vector<int>>& image,int primary,int color,int m,int n){
        image[row][col] = color;

        int delrow[4] = {-1, 1, 0, 0};
        int delcol[4] = {0, 0, -1, 1};

        for(int i=0; i<4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && image[nrow][ncol] == primary){
                dfs(nrow, ncol, image, primary, color, m, n);
            }
        }
    }

public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int primary = image[sr][sc];
        int m = image.size();
        int n = image[0].size();

        if(image[sr][sc] == color) return image;

        dfs(sr, sc, image, primary, color, m, n);

        return image;
    }
};