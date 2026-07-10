class Solution {
private:
    bool recursion(int n, long long value){
        if(n == value) return true;
        if(value > n) return false;

        return recursion(n, value*3);
    }
public:
    bool isPowerOfThree(int n) {
        long long value = 1;
        return recursion(n, value);
    }
};