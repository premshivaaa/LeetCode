class Solution {
private:
    bool recursion(int n, long long value){
        if(n == value) return true;
        if(value > n) return false;

        return recursion(n, value*4);
    }
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return false;
        return recursion(n, 1);
    }
};