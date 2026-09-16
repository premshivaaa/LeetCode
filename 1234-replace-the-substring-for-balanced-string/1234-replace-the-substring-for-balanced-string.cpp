class Solution {
public:
    int balancedString(string s) {
        int n = s.size();
        int target = n / 4;

        vector<int> cnt(4, 0);

        auto id = [&](char c) { 
            if(c == 'Q') return 0;
            if(c == 'W') return 1;
            if(c == 'E') return 2;
            return 3;
        };

        for(char c : s)
            cnt[id(c)]++;

        int ans = n;
        int left = 0;

        auto balanced = [&]() { // lamda fn for check
            return cnt[0] <= target &&
                   cnt[1] <= target &&
                   cnt[2] <= target &&
                   cnt[3] <= target;
        };

        for(int right = 0; right < n; right++) {

            cnt[id(s[right])]--;

            while(balanced()) {
                ans = min(ans, right - left + 1);

                cnt[id(s[left])]++;
                left++;
            }
        }

        return ans;
    }
};