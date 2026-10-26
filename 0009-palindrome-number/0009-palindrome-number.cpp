class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers and numbers ending in 0 (except 0 itself) are not palindromes
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversedHalf = 0;
        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }

        // When length is even: x == reversedHalf
        // When length is odd:  x == reversedHalf / 10 (removes the middle digit)
        return x == reversedHalf || x == reversedHalf / 10;
    }
};