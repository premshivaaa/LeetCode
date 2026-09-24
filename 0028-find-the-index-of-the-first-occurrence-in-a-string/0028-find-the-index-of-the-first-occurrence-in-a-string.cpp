class Solution {
public:
    int strStr(string haystack, string needle) {
        int index = -1, left = 0, right = 0, need = 0, n = haystack.size();
        while (right < haystack.size()) {
            if (haystack[right] == needle[need]) {
                while (right < n && need < needle.size() && haystack[right] == needle[need]) {
                    right++;
                    need++;
                }
            }
            if (need == needle.size()) {
                return left;
                break;
            } else
                need = 0;

            right = left + 1;
            left = right;
        }
        return -1;
    }
};