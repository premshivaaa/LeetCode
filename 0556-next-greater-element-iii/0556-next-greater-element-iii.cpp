class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);

        int pivot = -1;

        for (int i = s.size() - 2; i >= 0; i--) {
            if (s[i] < s[i + 1]) {
                pivot = i;
                break;
            }
        }

        if (pivot == -1)
            return -1; // smallest number is the next one

        for (int i = s.size() - 1; i > pivot; i--) {
            if (s[i] > s[pivot]) {
                swap(s[i], s[pivot]);
                break;
            }
        }

        reverse(s.begin() + pivot + 1, s.end());

        long long ans = stoll(s);

        return (ans > INT_MAX) ? -1 : (int)ans;
    }
};