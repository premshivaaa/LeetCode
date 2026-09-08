class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int left = 0, right = k - 1, count = 0;

        string s_num = to_string(num);

        while (right < s_num.size()) {
            string sb = s_num.substr(left, k);
            int div = stoi(sb);

            if (div != 0 && num % div == 0)
                count++;

            left++;
            right++;
        }

        return count;
    }
};