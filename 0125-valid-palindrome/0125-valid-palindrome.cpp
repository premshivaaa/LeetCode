class Solution {
public:
    bool isPalindrome(string s) {
        string modified;
        for (char c : s) {
            if (isalnum(c)) {
                modified += tolower(c);
            }
        }

        int left = 0, right = modified.size() - 1;
        while (left < right) {
            if (modified[left] != modified[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
};