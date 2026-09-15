class Solution {
public:
    int maxRepOpt1(string text) {
        vector<int> cnt(26, 0);
        for (char c : text) cnt[c - 'a']++;

        int n = text.size();
        int ans = 0;

        for (char ch = 'a'; ch <= 'z'; ch++) {
            int i = 0;
            while (i < n) {
                if (text[i] != ch) {
                    i++;
                    continue;
                }

                int j = i;
                while (j < n && text[j] == ch) j++; // one consecutive block + extra character
                int len1 = j - i;

                ans = max(ans, min(len1 + 1, cnt[ch - 'a']));

                if (j < n) {
                    int k = j + 1;
                    while (k < n && text[k] == ch) k++; // searching for two blocks seperated by only one diff character.
                    int len2 = k - (j + 1);

                    ans = max(ans, min(len1 + len2 + 1, cnt[ch - 'a']));
                }

                i = j;
            }
        }

        return ans;
    }
};