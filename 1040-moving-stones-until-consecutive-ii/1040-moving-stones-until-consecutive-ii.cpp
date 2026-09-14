class Solution {
public:
    vector<int> numMovesStonesII(vector<int>& stones) {
        int n = stones.size();
        sort(stones.begin(), stones.end());

        int maxMoves =
            max(stones[n - 2] - stones[0], stones[n - 1] - stones[1]) - (n - 2);

        int minMoves = n;
        int left = 0;

        for (int right = 0; right < n; right++) {
            while (stones[right] - stones[left] >= n)
                left++;

            int count = right - left + 1;

            if (count == n - 1 && stones[right] - stones[left] == n - 2) {
                minMoves = min(minMoves, 2);
            } else {
                minMoves = min(minMoves, n - count);
            }
        }

        return {minMoves, maxMoves};
    }
};