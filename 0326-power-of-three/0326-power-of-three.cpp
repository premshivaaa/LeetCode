class Solution {
private:
    bool recursion(int n, long long value) {
        if (value == n) return true;
        if (value > n) return false;

        return recursion(n, value * 3);
    }

public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        return recursion(n, 1);
    }
};