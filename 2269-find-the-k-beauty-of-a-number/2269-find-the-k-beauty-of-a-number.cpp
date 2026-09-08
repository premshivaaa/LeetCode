class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int n = s.size();

        int power = 1;
        for (int i = 1; i < k; i++)
            power *= 10;
        int window = 0;

        // Build first window
        for (int i = 0; i < k; i++)
            window = window * 10 + (s[i] - '0');

        int count = 0;

        if (window != 0 && num % window == 0)
            count++;

        // Slide the window
        for (int i = k; i < n; i++) {
            window %= power;                        // Remove leftmost digit
            window = window * 10 + (s[i] - '0');    // Add new digit

            if (window != 0 && num % window == 0)
                count++;
        }

        return count;
    }
};