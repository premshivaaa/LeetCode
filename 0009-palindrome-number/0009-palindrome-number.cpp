class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;

        long long palin = 0, n = x;
        while(n > 0){
            int digit = n % 10;
            palin = palin * 10 + digit;
            n /= 10;
        }
        return x == (int)palin;
    }
};