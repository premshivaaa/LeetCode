class Solution {
public:
    string pushDominoes(string dominoes) {
        string s = "L" + dominoes + "R";

        int i = 0;

        for (int j = 1; j < s.size(); j++) {
            if (s[j] == '.') continue;

            if (j - i > 1) {
                if (s[i] == s[j]) {
                    // L...L or R...R
                    for (int k = i + 1; k < j; k++)
                        s[k] = s[i];
                }
                else if (s[i] == 'R' && s[j] == 'L') {
                    // R...L
                    int left = i + 1;
                    int right = j - 1;

                    while (left < right) {
                        s[left++] = 'R';
                        s[right--] = 'L';
                    }
                }
                // L...R -> do nothing
            }

            i = j;
        }

        return s.substr(1, s.size() - 2);
    }
};