class Solution {
public:
    long long solve(vector<vector<int>>& coins, int k) {
        sort(coins.begin(), coins.end());

        long long ans = 0;
        long long sum = 0;

        int n = coins.size();
        int j = 0;

        for(int i = 0; i < n; i++) {

            long long start = coins[i][0];
            long long end = start + k - 1;

            while(j < n && coins[j][1] <= end) {
                sum += 1LL * (coins[j][1] - coins[j][0] + 1) * coins[j][2];
                j++;
            }

            long long cur = sum;

            if(j < n && coins[j][0] <= end) {
                long long overlap = end - coins[j][0] + 1;
                cur += overlap * coins[j][2];
            }

            ans = max(ans, cur);

            sum -= 1LL * (coins[i][1] - coins[i][0] + 1) * coins[i][2];
        }

        return ans;
    }


    long long maximumCoins(vector<vector<int>>& coins, int k) {

        long long ans = solve(coins, k);

        vector<vector<int>> rev;

        for(auto &x : coins) {
            rev.push_back({-x[1], -x[0], x[2]});
        }

        ans = max(ans, solve(rev, k));

        return ans;
    }
};