class Solution {
public:
    int maxRepOpt1(string text) {
        vector<int> freq(26);
        for (char c : text)
            freq[c - 'a']++;

        int n = text.size(), ans = 0;

        for (char ch = 'a'; ch <= 'z'; ch++) {
            int total = freq[ch - 'a'];
            if (total == 0)
                continue;

            int i = 0;
            while (i < n) {
                if (text[i] != ch) {
                    i++;
                    continue;
                }

                int j = i;
                while (j < n && text[j] == ch) // one consecutive block + extra character
                    j++;
                int left = j - i;

                ans = max(ans, min(left + 1, total));

                int k = j + 1;
                while (k < n && text[k] == ch) // searching for two blocks seperated by only one diff character.
                    k++;
                int right = k - (j + 1);

                ans = max(ans, min(left + right + 1, total));

                i = j;
            }
        }

        return ans;
    }
};