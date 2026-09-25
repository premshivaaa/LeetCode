class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();

        for(int i = 0; i < n; i++) {
            int start = i;

            while(i < n && s[i] != ' ')
                i++;

            reverse(s.begin() + start, s.begin() + i);
        }

        return s;
    }
};