class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        int n = nums.size();
        int start = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == key) {
                int left = max(start, i - k);
                int right = min(n - 1, i + k);

                for (int j = left; j <= right; j++) {
                    ans.push_back(j);
                }

                start = right + 1; // Move past already included indices
            }
        }

        return ans;
    }
};