class Solution {
public:
    int countKConstraintSubstrings(string s, int k) {
        int left = 0;
        int zeros = 0, ones = 0;
        int ans = 0;

        for (int right = 0; right < s.size(); right++) {
            if (s[right] == '0')
                zeros++;
            else
                ones++;

            while (zeros > k && ones > k) {
                if (s[left] == '0')
                    zeros--;
                else
                    ones--;
                left++;
            }

            ans += (right - left + 1);
        }

        return ans;
    }
};