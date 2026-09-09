class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n = colors.size();
        int count = 0;

        for (int i = 0; i < n; i++) {
            int prev = (i == 0) ? n - 1 : i - 1;
            int next = (i == n - 1) ? 0 : i + 1;

            if (colors[i] != colors[prev] &&
                colors[i] != colors[next]) {
                count++;
            }
        }

        return count;
    }
};