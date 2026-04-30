class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        
        vector<vector<bool>> reach(numCourses, vector<bool>(numCourses, false));

        for (auto &it : prerequisites) {
            reach[it[0]][it[1]] = true;
        }

        // Step 3: Floyd–Warshall to compute transitive closure
        for (int k = 0; k < numCourses; k++) {
            for (int i = 0; i < numCourses; i++) {
                for (int j = 0; j < numCourses; j++) {
                    if (reach[i][k] && reach[k][j]) {
                        reach[i][j] = true;
                    }
                }
            }
        }

        // Step 4: Answer queries
        vector<bool> ans;
        for (auto &it : queries) {
            ans.push_back(reach[it[0]][it[1]]);
        }

        return ans;
    }
};