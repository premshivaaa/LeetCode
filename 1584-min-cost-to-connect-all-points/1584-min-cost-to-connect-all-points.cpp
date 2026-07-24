class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> dist(n, INT_MAX);
        vector<int> vis(n, 0);
        dist[0] = 0;
        int ans = 0;

        for(int i=0; i<n; i++){
            int minIndex = -1;
            for(int j=0; j<n; j++){
                if(!vis[j] && (minIndex == -1 || dist[j] < dist[minIndex])) minIndex = j;
            }

            vis[minIndex] = 1;
            ans += dist[minIndex];

            for(int k=0; k<n; k++){
                if(!vis[k]){
                    int cost = abs(points[minIndex][0] - points[k][0]) + abs(points[minIndex][1] - points[k][1]);

                    dist[k] = min(dist[k], cost);
                }
            }
        }

        return ans;
    }
};