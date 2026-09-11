class Solution {
public:
    int longestSubstring(string s, int k) {
        int ans = 0;
        int n = s.size();

        for (int targetUnique = 1; targetUnique <= 26; targetUnique++) {
            vector<int> freq(26, 0);
            int left = 0, right = 0;
            int unique = 0;
            int countAtLeastK = 0;

            while (right < n) {
                if (freq[s[right] - 'a'] == 0)
                    unique++;
                freq[s[right] - 'a']++;
                if (freq[s[right] - 'a'] == k)
                    countAtLeastK++;
                right++;

                while (unique > targetUnique) {
                    if (freq[s[left] - 'a'] == k)
                        countAtLeastK--;
                    freq[s[left] - 'a']--;
                    if (freq[s[left] - 'a'] == 0)
                        unique--;
                    left++;
                }

                if (unique == targetUnique && unique == countAtLeastK)
                    ans = max(ans, right - left);
            }
        }

        return ans;
    }
};