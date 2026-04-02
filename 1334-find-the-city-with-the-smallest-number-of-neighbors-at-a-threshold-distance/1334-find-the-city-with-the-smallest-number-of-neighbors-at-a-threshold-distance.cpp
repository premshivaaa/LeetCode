class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        for(auto edge : edges){
            dist[edge[0]][edge[1]] = edge[2];
            dist[edge[1]][edge[0]] = edge[2];
        }
        for(int i=0; i<n; i++) dist[i][i] = 0;

        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(dist[i][k] == INT_MAX || dist[k][j] == INT_MAX) continue;

                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        int cityCount = n, topCity = -1;
        for(int i=0; i<n; i++){
            int counter = 0;
            for(int j=0; j<n; j++){
                if(dist[i][j] <= distanceThreshold) counter++;
            }
            if(counter <= cityCount){
                cityCount = counter;
                topCity = i;
            }
        }

        return topCity;
    }
};