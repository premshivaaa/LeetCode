class Solution {
public:
    bool queryString(string s, int n) {
        if (n > 2 * s.size()) return false;

        for (int i = n; i > n / 2; i--) {
            string t;
            int x = i;
            while (x) {
                t.push_back((x & 1) + '0');
                x >>= 1;
            }
            reverse(t.begin(), t.end());

            if (s.find(t) == string::npos)
                return false;
        }

        return true;
    }
};