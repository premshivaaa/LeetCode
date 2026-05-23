class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> group(n, 0);

        for (int i = 1; i < n; i++) {
            if (abs(nums[i] - nums[i - 1]) <= maxDiff)
                group[i] = group[i - 1];
            else
                group[i] = i;
        }

        vector<bool> ans;

        for (auto &q : queries) {
            ans.push_back(group[q[0]] == group[q[1]]);
        }

        return ans;
    }
};